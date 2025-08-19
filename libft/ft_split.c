/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:24:03 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/22 16:50:36 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_strings(char const *s, char c)
{
	int	strs;
	int	ctr;

	strs = 1;
	ctr = 0;
	if (!s)
		return (0);
	while (s[ctr] == c)
		ctr++;
	while (s[ctr])
	{
		if (s[ctr] == c && s[ctr + 1] != c && s[ctr + 1] != '\0')
			strs++;
		ctr++;
	}
	return (strs);
}

static void	terminate_strings(char *s, char c, int s_len)
{
	int	ctr;

	ctr = 0;
	while (ctr < s_len)
	{
		if (s[ctr] == c)
			s[ctr] = '\0';
		ctr++;
	}
}

static void	*free_str_of_strs(char ***str_of_strs, int idx)
{
	while (idx >= 0)
	{
		free((*str_of_strs)[idx]);
		idx--;
	}
	free(*str_of_strs);
	return (NULL);
}

static char	**split_strings(char *s, char c, int s_len, int strs)
{
	int		ctr;
	int		idx;
	char	**str_of_strs;

	ctr = 0;
	idx = 0;
	str_of_strs = malloc((strs + 1) * sizeof(char *));
	if (!str_of_strs)
		return (NULL);
	while (ctr < s_len)
	{
		if (s[ctr] != c && s[ctr] != '\0')
		{
			str_of_strs[idx] = ft_strdup(&s[ctr]);
			if (!str_of_strs[idx])
				return (free_str_of_strs(&str_of_strs, idx));
			idx++;
			while (s[ctr])
				ctr++;
		}
		ctr++;
	}
	str_of_strs[idx] = NULL;
	return (str_of_strs);
}

char	**ft_split(char *s, char c)
{
	int		s_len;
	int		strs;
	char	*s_copy;
	char	**s_return;

	if (!s)
		return (NULL);
	if (s[0] == '\0')
	{
		s_return = malloc(sizeof(char *));
		if (!s_return)
			return (NULL);
		s_return[0] = NULL;
		return (s_return);
	}
	s_copy = ft_strdup(s);
	if (!s_copy)
		return (NULL);
	s_len = ft_strlen(s_copy);
	strs = count_strings(s_copy, c);
	terminate_strings(s_copy, c, s_len);
	s_return = split_strings(s_copy, c, s_len, strs);
	free(s_copy);
	return (s_return);
}
