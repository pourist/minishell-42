/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppour-ba <ppour-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:17:37 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/03/21 00:52:51 by ppour-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_insert(char **str, char c, int pos)
{
	char	*new_str;
	size_t	len;

	if (!str || !*str)
		return ;
	len = ft_strlen(*str);
	new_str = (char *)ft_calloc(len + 2, sizeof(char));
	if (!new_str)
		return ;
	ft_memcpy(new_str, *str, pos);
	new_str[pos] = c;
	ft_memcpy(new_str + pos + 1, *str + pos, len - pos);
	new_str[len + 1] = '\0';
	free(*str);
	*str = new_str;
}
