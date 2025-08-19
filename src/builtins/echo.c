/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:38:38 by ppour-ba          #+#    #+#             */
/*   Updated: 2024/03/18 10:53:12 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	echo_n_flag(char *arg)
{
	int	i;

	if (!arg)
		return (0);
	i = 2;
	if (ft_strncmp(arg, "-n", 2) != 0)
		return (0);
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	pass_n_flags(char **args, int i)
{
	int	j;

	i++;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '-')
			j++;
		else
			return (i);
		while (args[i][j])
		{
			if (args[i][j] == 'n')
				j++;
			else
				return (i);
		}
		i++;
	}
	return (i);
}

int	echo(char **args, int fd)
{
	int	i;
	int	j;
	int	n_flag;

	n_flag = echo_n_flag(args[1]);
	i = 1;
	if (n_flag)
		i = pass_n_flags(args, i);
	while (args[i])
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			if (args[i][j] == '\\')
				j++;
			write(fd, &args[i][j], 1);
			j++;
		}
		if (args[i + 1] != NULL)
			write(fd, " ", 1);
		i++;
	}
	if (!n_flag)
		write(fd, "\n", 1);
	return (0);
}
