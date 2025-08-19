/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:33:51 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/14 17:59:35 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nbr(int nb)
{
	int	digits;

	digits = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	int		o_n;
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	o_n = n;
	len = len_nbr(n);
	if (n < 0)
	{
		n = -1 * n;
		len = 1 + len_nbr(n);
	}
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + 48;
		n = n / 10;
	}
	if (o_n < 0)
		str[0] = '-';
	return (str);
}
