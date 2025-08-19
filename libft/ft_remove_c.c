/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:41:41 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/02/23 14:16:17 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_remove_c(char **s, char c)
{
	int	ctr;
	int	ctr2;

	if (!s || !(*s))
		return ;
	ctr = 0;
	while ((*s)[ctr])
	{
		if ((*s)[ctr] == c)
		{
			ctr2 = ctr;
			while ((*s)[ctr2])
			{
				(*s)[ctr2] = (*s)[ctr2 + 1];
				ctr2++;
			}
			ctr--;
		}
		ctr++;
	}
}
