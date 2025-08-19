/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:47:55 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/03/21 16:14:48 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_sig;

int	ft_execvp(t_shell *sh, t_cmd *cmd)
{
	int		ctr;
	char	*cmd_path;
	char	*program;

	ctr = -1;
	program = ft_strjoin("/", cmd->parsed[0]);
	update_path(sh);
	if (!absolute_path_or_pwd(cmd))
	{
		while (sh->paths && sh->paths[++ctr])
		{
			cmd_path = ft_strjoin(sh->paths[ctr], program);
			if (!access(cmd_path, F_OK))
				break ;
			cmd_path = ft_freenull((void **)&cmd_path);
		}
		ft_freenull((void **)&program);
		if (!sh->paths || !cmd_path)
			return (print_error(CMD_E, sh, cmd->parsed[0]));
		ft_freenull((void **)&cmd->parsed[0]);
		cmd->parsed[0] = cmd_path;
	}
	if (execv(cmd->parsed[0], cmd->parsed) == -1)
		return (print_error(EXECV_E, sh, cmd->parsed[0]));
	return (1);
}

int	single_cmd(t_shell *sh, t_cmd *cmd)
{
	int		child_status;

	g_sig = 1;
	sh->exit_code = builtins(sh, cmd);
	if (sh->exit_code != -1)
		return (reset_stds(sh));
	sh->child = fork();
	if (sh->child == -1)
		return (print_error(99, sh, "fork error"));
	signal_setup(sh->child);
	if (!sh->child)
	{
		sh->exit_code = ft_execvp(sh, cmd);
		exit(free_exit(sh));
	}
	reset_stds(sh);
	waitpid(sh->child, &child_status, 0);
	if (WIFEXITED(child_status))
		sh->exit_code = WEXITSTATUS(child_status);
	else
		sh->exit_code = 128 + WTERMSIG(child_status);
	g_sig = 0;
	return (0);
}

int	multiple_cmdd(t_shell *sh, t_list *lst)
{
	int	pid;
	int	child_status;

	pid = fork();
	if (pid == 0)
		do_pipe(lst, sh);
	waitpid(pid, &child_status, 0);
	if (WIFEXITED(child_status))
		sh->exit_code = WEXITSTATUS(child_status);
	else
		sh->exit_code = 128 + WTERMSIG(child_status);
	return (0);
}

int	executor(t_shell *sh)
{
	t_list	*lst;
	t_cmd	*cmd;

	lst = *(sh->cmds);
	cmd = (t_cmd *)lst->content;
	if (!cmd->parsed[0] || !(*cmd->parsed[0]))
		return (0);
	if (lst->next == NULL)
		single_cmd(sh, cmd);
	else
		multiple_cmdd(sh, lst);
	g_sig = 0;
	return (1);
}
