/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:39:08 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/02/28 18:31:10 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_ptr(char *str, char *ptr1, char *ptr2)
{
	char	*end;
	char	*substr;
	char	*o_substr;

	end = str + ft_strlen(str);
	if (!ptr2 && (str && ptr1) && (ptr1 <= end) && (ptr1 >= str))
		return (ft_strdup(ptr1));
	if (!ptr1 || !ptr2 || !str || ptr1 < str || ptr2 < str || \
	ptr1 > end || ptr2 > end || ptr1 > ptr2)
		return (NULL);
	substr = ft_calloc(ptr2 - ptr1 + 1, sizeof(char));
	if (!substr)
		return (NULL);
	o_substr = substr;
	while (ptr1 != ptr2)
	{
		*substr = *ptr1;
		ptr1++;
		substr++;
	}
	*substr = '\0';
	return (o_substr);
}
