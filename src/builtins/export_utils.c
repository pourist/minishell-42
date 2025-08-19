/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:12:22 by ppour-ba          #+#    #+#             */
/*   Updated: 2024/02/14 14:28:03 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	print_export(t_env *env)
{
	while (env)
	{
		if (env->value)
			printf("declare -x %s=\"%s\"\n", env->key, env->value);
		else
			printf("declare -x %s=\"\"\n", env->key);
		env = env->next;
	}
	return (0);
}

int	contains_char(char c, char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
