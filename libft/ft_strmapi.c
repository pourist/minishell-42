/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:00:26 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/14 18:13:27 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapped_s;
	int		ctr;

	if (!s)
		return (NULL);
	if (!f)
		return (NULL);
	ctr = 0;
	mapped_s = malloc(ft_strlen(s) + 1);
	if (!mapped_s)
		return (NULL);
	while (s[ctr])
	{
		mapped_s[ctr] = f(ctr, s[ctr]);
		ctr++;
	}
	mapped_s[ctr] = '\0';
	return (mapped_s);
}
