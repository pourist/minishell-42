/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppour-ba <ppour-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:07:51 by ppour-ba          #+#    #+#             */
/*   Updated: 2024/03/21 00:53:17 by ppour-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	valid_key(char *str)
{
	int	i;

	i = 1;
	if (!(ft_isalpha(str[0]) || (str[0] == '_' )))
		return (0);
	while (str[i] != '=' && str[i] != '\0')
	{
		if (!(ft_isalnum(str[i]) || (str[i] == '_')))
			return (0);
		i++;
	}
	return (1);
}

int	add_to_list(t_shell	*shell, char **args, int index)
{
	t_env	*current;
	t_env	*node;

	node = new_env_list(args[index]);
	current = *shell->env;
	while (current)
	{
		if (!(ft_strncmp(current->key, node->key, ft_strlen(node->key) + 1)))
		{
			ft_freenull((void **)&current->value);
			ft_freenull((void **)&node->key);
			current->value = node->value;
			ft_freenull((void **)&node);
			current->include_env = 1;
			return (0);
		}
		current = current->next;
	}
	add_node_to_end(shell->env, node);
	return (0);
}

int	without_value(t_shell *shell, char **args, int index)
{
	t_env	*current;
	t_env	*node;

	current = *shell->env;
	while (current)
	{
		if (!(ft_strncmp(current->key, args[index],
					ft_strlen(args[index]) + 1)))
			return (0);
		current = current->next;
	}
	node = (t_env *)malloc(sizeof(t_env));
	node->value = NULL;
	node->include_env = 0;
	node->key = (char *)malloc(ft_strlen(args[index]) + 1);
	ft_strlcpy(node->key, args[index],
		ft_strlen(args[index]) + 1);
	node->next = NULL;
	add_node_to_end(shell->env, node);
	return (0);
}

int	export(t_shell *shell, char **args)
{
	int	i;
	int	eq_index;

	i = 1;
	if (args[1] == NULL)
		return (print_export(*shell->env));
	while (args[i])
	{
		eq_index = contains_char('=', args[i]);
		if ((eq_index == 0) || !valid_key(args[i]))
		{
			print_error(99, NULL, "Error: export: not a valid identifier");
			return (1);
		}
		else if (eq_index == -1)
			without_value(shell, args, i);
		else
			add_to_list(shell, args, i);
		i++;
	}
	return (0);
}
