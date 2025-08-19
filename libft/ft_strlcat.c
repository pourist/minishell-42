/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:26:37 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/15 16:20:49 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	remaining;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size < dest_len)
		return (size + src_len);
	remaining = size - dest_len;
	while (*dst)
		dst++;
	if (remaining > 0)
	{
		while (*src && remaining > 1)
		{
			*dst = *src;
			remaining --;
			src++;
			dst++;
		}
		*dst = '\0';
	}
	return (dest_len + src_len);
}
