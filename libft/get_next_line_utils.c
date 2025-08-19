/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:45:51 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/02/21 15:08:30 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	char	*o_concat;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	concat = malloc(ft_strlen(s1)+ft_strlen(s2)+1);
	if (!concat)
		return (NULL);
	o_concat = concat;
	while (*s1)
	{
		*concat = *s1;
		concat++;
		s1++;
	}
	while (*s2)
	{
		*concat = *s2;
		concat++;
		s2++;
	}
	*concat = '\0';
	return (o_concat);
}

char	*ft_strchr(const char *s, int c)
{
	int				ctr;
	unsigned char	*s_copy;

	if (!s)
		return (NULL);
	s_copy = (unsigned char *) s;
	c = (char) c;
	ctr = 0;
	while (s_copy[ctr])
	{
		if (s_copy[ctr] == c)
			return ((char *)&s_copy[ctr]);
		ctr++;
	}
	if (s_copy[ctr] == c)
		return ((char *)&s_copy[ctr]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	char	*o_copy;

	copy = malloc((ft_strlen(s) + 1) * sizeof(char));
	o_copy = copy;
	if (copy == NULL)
		return (NULL);
	else
	{
		while (*s)
		{
			*copy = *s;
			copy++;
			s++;
		}
	}
	*copy = '\0';
	return (o_copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*o_sub;
	size_t	len_s;

	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	s = s + start;
	o_sub = sub;
	while (s && len > 0)
	{
		*sub = *s;
		sub++;
		s++;
		len--;
	}
	*sub = '\0';
	return (o_sub);
}
