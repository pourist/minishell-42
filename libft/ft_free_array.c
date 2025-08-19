/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:11:21 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/03/19 19:11:39 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(char **array)
{
	int	ctr;

	if (!array)
		return ;
	if (*array)
	{
		ctr = 0;
		while (array[ctr])
		{
			ft_freenull((void **)&array[ctr]);
			ctr++;
		}
	}
	ft_freenull((void **)&array);
}
