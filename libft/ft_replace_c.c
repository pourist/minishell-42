/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:47:47 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/02/23 14:15:54 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_replace_c(char **s, char c, char r)
{
	int	ctr;

	ctr = 0;
	if (!s || !(*s))
		return ;
	while ((*s)[ctr])
	{
		if ((*s)[ctr] == c)
			(*s)[ctr] = r;
		ctr++;
	}
}
