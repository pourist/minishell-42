/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:47:58 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/03/19 19:13:24 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_env(t_env **env)
{
	t_env	*tmp;
	t_env	*tmp_next;

	tmp = *env;
	while (tmp)
	{
		ft_freenull((void **)&tmp->key);
		ft_freenull((void **)&tmp->value);
		tmp_next = tmp->next;
		ft_freenull((void **)&tmp);
		tmp = tmp_next;
	}
	ft_freenull((void **)&env);
}

int	free_all(t_shell *sh)
{
	if (sh->cmds)
		free_cmd(sh);
	ft_freenull((void **)&sh->prompt);
	ft_freenull((void **)&sh->input);
	ft_free_array(sh->paths);
	free_env(sh->env);
	ft_freenull((void **)&sh);
	rl_clear_history();
	return (0);
}

void	free_redlist(t_operation *op)
{
	t_redlist	*tmp;
	t_redlist	*tmp_next;

	tmp = op->redir;
	while (tmp)
	{
		tmp_next = tmp->next;
		ft_freenull((void **)&tmp);
		tmp = tmp_next;
	}
}

int	free_cmd(t_shell *sh)
{
	t_list	*lst;
	t_list	*tmp_lst;
	t_cmd	*cmd;

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

int	free_pipe(t_pipe *pipe_s)
{
	if (pipe_s)
	{
		ft_freenull((void **)&pipe_s->pipes);
		ft_freenull((void **)&pipe_s->pid);
		ft_freenull((void **)&pipe_s);
	}
	return (0);
}
