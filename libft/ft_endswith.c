/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:44:13 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/03/18 11:40:38 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_endswith(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (0);
	if (!*s2)
		return (1);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!len_s1 || !len_s2 || len_s1 < len_s2)
		return (0);
	s1 = s1 + (len_s1 - len_s2);
	if (!ft_strcmp(s1, s2))
		return (1);
	else
		return (0);
}
