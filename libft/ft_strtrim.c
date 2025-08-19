/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:30:29 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/22 12:20:09 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	find_start_end(char const *s1, char const *set, int direction)
{
	int	ctr;

	if (direction > 0)
	{
		ctr = 0;
		while (s1[ctr] && ft_strchr((char *)set, s1[ctr]))
			ctr++;
	}
	else
	{
		ctr = ft_strlen(s1);
		while (ft_strchr((char *)set, s1[ctr]))
			ctr--;
	}
	return (ctr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		ctr;
	char	*trimmed;

	if (!s1 || !set || !(*s1) || !(*set))
		return (ft_strdup((char *)s1));
	start = find_start_end(s1, set, 1);
	if ((size_t) start == ft_strlen(s1))
		return (ft_strdup((char *)&s1[start]));
	end = find_start_end(s1, set, -1);
	ctr = 0;
	trimmed = malloc((end - start) + 2);
	if (!trimmed)
		return (NULL);
	while (start <= end)
	{
		trimmed[ctr] = s1[start];
		ctr++;
		start++;
	}
	trimmed[ctr] = '\0';
	return (trimmed);
}
