/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:35:36 by ppour-ba          #+#    #+#             */
/*   Updated: 2024/03/18 15:50:31 by ppour-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	env(t_env *env)
{
	while (env)
	{
		if (env->include_env && env->key[0] != '\0')
		{
			if (env->value != NULL)
				printf("%s=%s\n", env->key, env->value);
			else
				printf("%s=\n", env->key);
		}
		env = env->next;
	}
	return (0);
}

char	*ft_getenv(t_shell *sh, char *key)
{
	t_env	*env;

	if (key[0] == 36)
		key = &key[1];
	if (key[0] == '?')
		return (ft_itoa(sh->exit_code));
	env = *(sh->env);
	while (env)
	{
		if (!ft_strcmp(env->key, key))
			return (ft_strdup(env->value));
		env = env->next;
	}
	return (ft_strdup(""));
}
