/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:03:05 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/03/20 17:52:54 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_sig;

int	heredoc_ctrlc(t_shell *sh)
{
	t_list	*lst;
	t_list	*tmp_lst;
	t_cmd	*cmd;

	ft_freenull((void **)&sh->input);
	lst = *sh->cmds;
	while (lst)
	{
		cmd = (t_cmd *)lst->content;
		cmd->raw = ft_freenull((void **)&cmd->raw);
		ft_free_array(cmd->parsed);
		tmp_lst = lst->next;
		ft_freenull((void **)&lst);
		lst = tmp_lst;
		free_redlist(cmd->op);
		ft_freenull((void **)&cmd->op);
		ft_freenull((void **)&cmd);
	}
	ft_freenull((void **)&sh->cmds);
	return (0);
}

static int	here_doc(char *del, int fd, t_shell *sh)
{
	char	*buff;
	char	*tmp_del;

	tmp_del = ft_strjoin(del, "\n");
	g_sig = 0;
	while (g_sig != SIGINT)
	{
		write(1, "> ", 2);
		buff = get_next_line(0);
		if (!buff || !ft_strcmp(tmp_del, buff))
			break ;
		write(fd, buff, ft_strlen(buff));
		ft_freenull((void **)&buff);
		buff = NULL;
	}
	ft_freenull((void **)&tmp_del);
	if (!buff && g_sig != SIGINT)
		return (print_error(99, sh, "\nError: here-document delimited by eof"));
	ft_freenull((void **)&buff);
	ft_freenull((void **)&del);
	return (0);
}

int	start_heredoc(char *del, t_cmd *cmd, t_shell *sh)
{
	if (cmd->heredoc[1] == 0)
		close(cmd->heredoc[0]);
	if (pipe(cmd->heredoc) == -1)
		return (-1);
	signal_setup(-1);
	here_doc(del, cmd->heredoc[1], sh);
	reset_stds(sh);
	signal_setup(1);
	close(cmd->heredoc[1]);
	if (g_sig == SIGINT)
		close(cmd->heredoc[0]);
	cmd->heredoc[1] = 0;
	return (1);
}

int	heredoc_handle(t_cmd *cmd, t_shell *sh)
{
	t_redlist	*temp;

	temp = cmd->op->redir;
	cmd->heredoc[1] = 1;
	while (temp)
	{
		if (temp->type == REDIRECT_HEREDOC)
			start_heredoc(temp->file_name, cmd, sh);
		temp = temp->next;
	}
	if (g_sig == SIGINT)
	{
		heredoc_ctrlc(sh);
		g_sig = 0;
	}
	return (0);
}
