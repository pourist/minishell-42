/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:00:28 by ppour-ba          #+#    #+#             */
/*   Updated: 2024/03/19 17:56:35 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	builtins(t_shell *sh, t_cmd *cmd)
{
	char	*program;

	if (handle_redir(cmd, sh) == -1)
		return (1);
	program = cmd->op->command[0];
	if (!ft_strcmp(cmd->parsed[0], "exit"))
		return (minishell_exit(cmd->parsed, sh));
	if (!program || !ft_strcmp(program, "exit"))
		return (minishell_exit(cmd->op->command, sh));
	else if (!ft_strcmp(program, "export"))
		return (export(sh, cmd->op->command));
	else if (!ft_strcmp(program, "unset"))
		return (unset(sh, cmd->op->command));
	else if (!ft_strcmp(program, "echo"))
		return (echo(cmd->op->command, sh->fd));
	else if (!ft_strcmp(program, "pwd"))
		return (pwd(sh->fd));
	else if (!ft_strcmp(program, "env"))
		return (env(*(sh->env)));
	else if (!ft_strcmp(program, "cd"))
		return (cd(cmd->op->command, sh));
	return (-1);
}
