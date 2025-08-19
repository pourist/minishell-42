/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:36:01 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/22 16:28:01 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	ctr;
	char	*ptr_src;
	char	*ptr_dest;

	if (n && (!dest) && (!src))
		return (NULL);
	ctr = 0;
	ptr_src = (char *)src;
	ptr_dest = dest;
	while (ctr < n)
	{
		ptr_dest[ctr] = ptr_src[ctr];
		ctr++;
	}
	return ((void *)dest);
}
