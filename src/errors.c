/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:47:52 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/03/21 14:45:09 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	print_error(int type, t_shell *sh, char *str)
{
	if (type == MALLOC_E)
	{
		write(2, "malloc error - exiting\n", 24);
		sh->end = 1;
		free_all(sh);
	}
	else if (type == CMD_E)
	{
		ft_putstr_fd(str, 2);
		write(2, ": command not found\n", 21);
		sh->exit_code = 127;
		free_cmd(sh);
		return (127);
	}
	else if (type == EXECV_E)
	{
		write(2, "execv error (permissions?): ", 29);
		ft_putendl_fd(str, 2);
		sh->exit_code = 126;
		free_cmd(sh);
		return (126);
	}
	else
		ft_putendl_fd(str, 2);
	return (0);
}
