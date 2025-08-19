/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:33:28 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/02/16 18:06:26 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_ascii(int c)
{
	if (c > 255)
		return (c % 256);
	return (c);
}

char	*ft_strchr(const char *s, int c)
{
	int				ctr;
	unsigned char	*s_copy;

	s_copy = (unsigned char *) s;
	c = check_ascii(c);
	ctr = 0;
	if (!s)
		return (NULL);
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
