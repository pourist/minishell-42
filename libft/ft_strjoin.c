/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:19:53 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/14 11:29:47 by jstrozyk         ###   ########.fr       */
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
