/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:51:15 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/22 15:03:52 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0)
	{
		if (__SIZE_MAX__ / nmemb < size)
			return (NULL);
	}
	ptr = malloc(nmemb * size);
	if (ptr)
		ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
