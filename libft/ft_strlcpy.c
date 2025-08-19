/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:53:40 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/15 17:50:30 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (size > 1 && *src)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	if (size != 0)
		*dst = '\0';
	return (src_len);
}
