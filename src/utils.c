/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:59:03 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/03/21 16:09:37 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_arraylen(char **array)
{
	size_t	len;

	len = 0;
	if (!array || !*array)
		return (0);
	while (array[len])
		len++;
	return (len);
}

char	*set_prompt(void)
{
	char	*prompt;

	if (getenv("USER"))
		prompt = ft_strjoin(getenv("USER"), "@minishell!?> ");
	else
		prompt = ft_strdup("guest@minishell!?> ");
	return (prompt);
}

static void	add_spaces(char **str, int i, char c)
{
	while (str && *str && (*str)[i])
	{
		if ((*str)[i] == 34 || (*str)[i] == 39)
		{
			c = (*str)[i++];
			while ((*str)[i] && (*str)[i] != c)
				i++;
			i++;
		}
		if ((*str)[i] && ((*str)[i] == '<' || (*str)[i] == '>'))
		{
			if (i && (*str)[i - 1] != ' ')
				ft_insert(str, ' ', i++);
			i++;
			if (((*str)[i] == '<' || (*str)[i] == '>'))
				i++;
			if ((*str)[i] && (*str)[i] != ' ')
				ft_insert(str, ' ', i);
		}
		if ((*str)[i])
			i++;
	}
}

int	verify_redirects(char **s)
{
	int		i;
	char	c;

	i = -1;
	add_spaces(s, 0, 0);
	while ((*s)[++i])
	{
		if ((*s)[i] == 34 || (*s)[i] == 39 || (*s)[i] == 60 || (*s)[i] == 62)
		{
			c = (*s)[i++];
			while ((c == 34 || c == 39) && (*s)[i] && (*s)[i] != c)
				i++;
			if ((*s)[i] == (*s)[i - 1])
				i++;
			if (!(*s)[i])
				return (1);
			while ((*s)[i] == 32 || (*s)[i] == 9)
				i++;
			if (ft_strchr(METACHARS, (*s)[i]))
				return (0);
		}
	}
	return (1);
}

int	reset_stds(t_shell *sh)
{
	dup2(sh->std_in, 0);
	dup2(sh->std_out, 1);
	return (0);
}
