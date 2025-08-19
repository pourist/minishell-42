/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_red.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:28:59 by ppour-ba          #+#    #+#             */
/*   Updated: 2024/03/20 18:09:29 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	redirect_out(char *file_name, t_shell *sh)
{
	close(1);
	if (ft_startswith(file_name, "$"))
	{
		reset_stds(sh);
		print_error(99, NULL, "Error: Ambiguous redirect");
		return (0);
	}
	else if (open(file_name, O_WRONLY | O_TRUNC | O_CREAT, 0666) < 0)
	{
		reset_stds(sh);
		print_error(99, NULL, "Error: Permission denied");
		return (0);
	}
	return (1);
}

int	redirect_append(char *file_name, t_shell *sh)
{
	close(1);
	if (ft_startswith(file_name, "$"))
	{
		reset_stds(sh);
		print_error(99, NULL, "Error: Ambiguous redirect");
		return (0);
	}
	else if (open(file_name, O_WRONLY | O_APPEND | O_CREAT, 0666) < 0)
	{
		reset_stds(sh);
		print_error(99, NULL, "Error: Permission denied");
		return (0);
	}
	return (1);
}

int	redirect_in(char *file_name, t_shell *sh)
{
	int	file;

	if (ft_startswith(file_name, "$"))
	{
		reset_stds(sh);
		print_error(99, NULL, "Error: Ambiguous redirect");
		return (0);
	}
	else if (access(file_name, F_OK) != 0)
	{
		reset_stds(sh);
		print_error(99, NULL, "Error: No such file or directory");
		return (0);
	}
	else
	{
		file = open(file_name, O_RDONLY, 0666);
		dup2(file, STDIN_FILENO);
	}
	return (1);
}

int	handle_redir(t_cmd *cmd, t_shell *sh)
{
	t_redlist	*t;

	t = cmd->op->redir;
	while (t && sh)
	{
		if (t->type == REDIRECT_OUT && !redirect_out(t->file_name, sh))
			return (-1);
		if (t->type == REDIRECT_APPEND && !redirect_append(t->file_name, sh))
			return (-1);
		if (t->type == REDIRECT_IN && !redirect_in(t->file_name, sh))
			return (-1);
		if (t->type == REDIRECT_HEREDOC)
		{
			dup2(cmd->heredoc[0], STDIN_FILENO);
			close(cmd->heredoc[0]);
		}
		t = t->next;
	}
	return (0);
}

int	execute_command(t_cmd *cmd, t_shell *sh)
{
	sh->exit_code = builtins(sh, cmd);
	if (sh->exit_code == -1)
		ft_execvp(sh, cmd);
	exit(free_exit(sh));
}
