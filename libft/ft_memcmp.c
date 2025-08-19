/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:42:53 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/17 15:25:13 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	ctr;

	ctr = 0;
	if (n == 0)
		return (0);
	while (ctr < n && ((unsigned char *)s1)[ctr] == ((unsigned char *)s2)[ctr])
		ctr++;
	if (ctr < n)
		return (((unsigned char *)s1)[ctr] - ((unsigned char *)s2)[ctr]);
	return (0);
}
