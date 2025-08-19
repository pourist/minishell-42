/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:46:16 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/20 12:52:43 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				ctr;
	const unsigned char	*char_ptr;
	unsigned char		c_copy;

	ctr = 0;
	c_copy = (unsigned char)c;
	char_ptr = (const unsigned char *)s;
	while (ctr < n)
	{
		if (char_ptr[ctr] == c_copy)
			return ((void *)&char_ptr[ctr]);
		ctr++;
	}
	return (NULL);
}
