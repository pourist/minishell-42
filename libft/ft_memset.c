/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:35:54 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/15 16:46:32 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	ctr;
	char	*ptr;

	ctr = 0;
	ptr = (char *) s;
	while (ctr < n)
	{
		ptr[ctr] = c;
		ctr++;
	}
	return (s);
}
