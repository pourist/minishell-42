/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:04:28 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/02/19 13:44:34 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	char	*o_copy;

	if (!s)
		return (NULL);
	copy = malloc((ft_strlen(s) + 1) * sizeof(char));
	o_copy = copy;
	if (copy == NULL)
		return (NULL);
	else
	{
		while (*s)
		{
			*copy = *s;
			copy++;
			s++;
		}
	}
	*copy = '\0';
	return (o_copy);
}
