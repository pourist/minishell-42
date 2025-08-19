/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:26:53 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/22 16:20:14 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*b_tmp;
	const char	*l_tmp;
	size_t		len_tmp;

	if (!*little)
		return ((char *) big);
	while (*big != '\0' && len > 0)
	{
		if (*big == *little)
		{
			b_tmp = big;
			l_tmp = little;
			len_tmp = len;
			while (*l_tmp != '\0' && *b_tmp == *l_tmp && len_tmp-- > 0)
			{
				b_tmp++;
				l_tmp++;
			}
			if (*l_tmp == '\0')
				return ((char *) big);
		}
		big++;
		len--;
	}
	return (NULL);
}
