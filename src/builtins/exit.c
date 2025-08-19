/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppour-ba <ppour-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:58:04 by ppour-ba          #+#    #+#             */
/*   Updated: 2024/03/20 22:43:32 by ppour-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_isnumber(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	minishell_exit(char **args, t_shell *sh)
{
	ft_putendl_fd("exit", sh->fd);
	if (!args || !args[1])
	{
		sh->end = 1;
	}
	else if (ft_isnumber(args[1]) && args[2])
	{
		print_error(99, sh, "minishell: exit: too many arguments\n");
		sh->exit_code = 1;
	}
	else if (!ft_isnumber(args[1]))
	{
		sh->end = 1;
		sh->exit_code = 2;
		print_error(99, sh, "minishell: exit: numeric argument required\n");
	}
	else
	{
		sh->end = 1;
		sh->exit_code = ft_atoi(args[1]);
	}
	return ((unsigned char)sh->exit_code);
}
