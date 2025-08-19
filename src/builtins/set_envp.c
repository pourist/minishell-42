/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:36:42 by ppour-ba          #+#    #+#             */
/*   Updated: 2024/03/21 15:08:13 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_env	*new_env_list(char *str)
{
	t_env	*node;
	int		i;

	node = (t_env *)malloc(sizeof(t_env));
	if (node == NULL)
		return (NULL);
	i = contains_char('=', str);
	node->key = (char *)malloc(i + 1);
	ft_strlcpy(node->key, str, i + 1);
	node->value = (char *)malloc(ft_strlen(str + i));
	ft_strlcpy(node->value, str + i + 1, ft_strlen(str + i));
	node->include_env = 1;
	node->next = NULL;
	return (node);
}

t_env	**set_env_list(char **envp, char *argv_zero)
{
	int		i;
	t_env	**env_list;
	char	*path;

	path = ft_strjoin("0=", argv_zero);
	env_list = (t_env **)malloc(sizeof(t_env));
	*env_list = new_env_list(path);
	(*env_list)->include_env = 0;
	i = 0;
	while (envp[i])
		add_node_to_end(env_list, new_env_list(envp[i++]));
	ft_freenull((void **)&path);
	return (env_list);
}

t_env	*find_last_node(t_env *lst)
{
	t_env	*last;

	last = lst;
	while (last && last->next != NULL)
		last = last->next;
	return (last);
}

void	add_node_to_end(t_env **lst, t_env *new)
{
	t_env	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		last = find_last_node(*lst);
		last->next = new;
	}
}
