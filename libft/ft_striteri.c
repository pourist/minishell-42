/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:09:47 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/15 17:48:12 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	ctr;

	if (!s)
		return ;
	if (!f)
		return ;
	ctr = 0;
	while (s[ctr])
	{
		f(ctr, &s[ctr]);
		ctr++;
	}
}
