/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:10:00 by ppour-ba          #+#    #+#             */
/*   Updated: 2024/03/18 15:44:16 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	dup_set(int r, int w)
{
	if (dup2(r, 0) == -1 || dup2(w, 1) == -1)
		return (-1);
	return (0);
}

void	close_pipes(t_pipe	*pipe_s)
{
	int	i;

	i = 0;
	while (i < (pipe_s->pipe_number))
		close(pipe_s->pipes[i++]);
}

void	child(int i, t_pipe *pipe_s, t_shell *sh, t_list *node)
{
	t_cmd	*cmd;

	cmd = node->content;
	pipe_s->pid[i] = fork();
	if (pipe_s->pid[i] == 0)
	{
		if (i == 0)
			dup2(pipe_s->pipes[1], STDOUT_FILENO);
		else if (i == pipe_s->cmnd_numb - 1)
			dup2(pipe_s->pipes[(i * 2) - 2], STDIN_FILENO);
		else
			dup_set(pipe_s->pipes[(i * 2) - 2], pipe_s->pipes[(i * 2) + 1]);
		close_pipes(pipe_s);
		free_pipe(pipe_s);
		execute_command(cmd, sh);
	}
}

t_pipe	*pipe_init(t_list *lst)
{
	int		i;
	t_pipe	*pipe_s;

	i = 0;
	pipe_s = (t_pipe *)malloc(sizeof(t_pipe));
	pipe_s->cmnd_numb = ft_lstsize(lst);
	pipe_s->pipe_number = (pipe_s->cmnd_numb - 1) * 2;
	pipe_s->pipes = (int *)malloc(sizeof(int) * pipe_s->pipe_number);
	pipe_s->pid = (int *)malloc(sizeof(int) * pipe_s->cmnd_numb);
	while (i < pipe_s->cmnd_numb - 1)
	{
		if (pipe(pipe_s->pipes + (2 * i)) < 0)
			return (NULL);
		i++;
	}
	return (pipe_s);
}

int	do_pipe(t_list *lst, t_shell *sh)
{
	t_pipe	*pipe_s;
	int		i;
	t_list	*node;
	int		child_status;

	pipe_s = pipe_init(lst);
	i = 0;
	node = lst;
	while (node)
	{
		child(i, pipe_s, sh, node);
		node = node->next;
		i++;
	}
	close_pipes(pipe_s);
	i = -1;
	while (++i < (pipe_s->cmnd_numb) - 1)
		waitpid(pipe_s->pid[i], NULL, 0);
	waitpid(pipe_s->pid[i], &child_status, 0);
	if (WIFEXITED(child_status))
		sh->exit_code = WEXITSTATUS(child_status);
	else
		sh->exit_code = 128 + WTERMSIG(child_status);
	free_pipe(pipe_s);
	exit (sh->exit_code);
}
