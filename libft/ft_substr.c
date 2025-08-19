/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:08:01 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/14 11:27:35 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
