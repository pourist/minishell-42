/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:44:48 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/22 16:17:20 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip_wspce(const char **str)
{
	while ((**str <= 13 && **str >= 9) || **str == 32)
		(*str)++;
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	integer;

	sign = 1;
	integer = 0;
	skip_wspce(&nptr);
	if (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			sign = -1 * sign;
		nptr++;
	}
	while (*nptr <= 57 && *nptr >= 48)
	{
		integer = (10 * integer) + (*nptr - 48);
		nptr++;
	}
	return (sign * integer);
}
