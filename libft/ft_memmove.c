/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:42:57 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/15 16:46:06 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	ctr;

	ctr = 0;
	if (n == 0 || dest == src)
		return (dest);
	if ((char *)src < (char *)dest)
	{
		while (n > 0)
		{
			((char *)dest)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		while (ctr < n)
		{
			((char *)dest)[ctr] = ((char *)src)[ctr];
			ctr++;
		}
	}
	return (dest);
}
