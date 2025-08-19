/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:26:22 by ppour-ba          #+#    #+#             */
/*   Updated: 2024/03/19 19:09:33 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	unset(t_shell *shell, char **args)
{
	int		i;
	t_env	*node;
	t_env	*next;

	i = 1;
	while (args[i])
	{
		node = *shell->env;
		while (node)
		{
			next = node->next;
			if (next && !ft_strncmp(next->key, args[i],
					ft_strlen(args[i])))
			{
				node->next = next->next;
				ft_freenull((void **)&next->key);
				if (next->value)
					ft_freenull((void **)&next->value);
				ft_freenull((void **)&next);
			}
			node = node->next;
		}
		i++;
	}
	return (0);
}
