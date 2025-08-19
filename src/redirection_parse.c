/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:46:40 by ppour-ba          #+#    #+#             */
/*   Updated: 2024/03/19 19:09:33 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	is_red(char *str)
{
	if (!ft_strcmp(str, "<") || !ft_strcmp(str, "<<"))
		return (1);
	if (!ft_strcmp(str, ">") || !ft_strcmp(str, ">>"))
		return (1);
	return (0);
}

t_redlist	*new_red(char *red, char *file_name)
{
	t_redlist	*node;

	node = (t_redlist *)malloc(sizeof(t_redlist));
	if (node == NULL)
		return (NULL);
	node->file_name = file_name;
	if (!ft_strcmp(red, "<"))
		node->type = REDIRECT_IN;
	if (!ft_strcmp(red, ">>"))
		node->type = REDIRECT_APPEND;
	if (!ft_strcmp(red, ">"))
		node->type = REDIRECT_OUT;
	if (!ft_strcmp(red, "<<"))
		node->type = REDIRECT_HEREDOC;
	node->next = NULL;
	return (node);
}

t_redlist	*find_last_red(t_redlist *lst)
{
	t_redlist	*last;

	last = lst;
	while (last && last->next != NULL)
		last = last->next;
	return (last);
}

void	add_to_red_list(t_redlist **lst, t_redlist *new)
{
	t_redlist	*last;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = find_last_red(*lst);
		last->next = new;
	}
}

t_operation	*red_parse(char **line)
{
	t_operation	*op;
	int			i;
	int			j;

	i = 0;
	j = 0;
	op = (t_operation *)malloc(sizeof(t_operation));
	op->command = ft_calloc(ft_arraylen(line) + 1, sizeof(char *));
	op->redir = NULL;
	while (line[i])
	{
		if (!is_red(line[i]))
		{
			op->command[j++] = line[i++];
		}
		else
		{
			add_to_red_list(&op->redir, new_red(line[i], line[i + 1]));
			ft_freenull((void **)&line[i]);
			i += 2;
		}
	}
	return (op);
}
