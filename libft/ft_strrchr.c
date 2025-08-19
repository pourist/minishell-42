/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:38:36 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/17 17:18:16 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_ascii(int c)
{
	if (c > 255)
		return (c % 256);
	return (c);
}

char	*ft_strrchr(const char *s, int c)
{
	int	ctr;
	int	c_pos;

	ctr = 0;
	c_pos = -1;
	c = check_ascii(c);
	while (s[ctr])
	{
		if (s[ctr] == c)
			c_pos = ctr;
		ctr++;
	}
	if (s[ctr] == c)
		c_pos = ctr;
	if (c_pos != -1)
		return ((char *)&s[c_pos]);
	else
		return (NULL);
}
