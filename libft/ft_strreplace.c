/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:47:57 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/03/18 11:40:46 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strreplace(char **str, char *find, char *replace)
{
	size_t	total_len;
	char	*substr;
	char	*tmp;

	substr = ft_strnstr(*str, find, ft_strlen(*str));
	if (!str || !*str || !substr)
		return ;
	total_len = ft_strlen(*str) - ft_strlen(find) + ft_strlen(replace) + 1;
	tmp = ft_calloc(total_len, sizeof(char));
	if (!tmp)
		return ;
	ft_strlcpy(tmp, *str, (substr - (*str)) + 1);
	ft_strlcpy((tmp + (substr - (*str))), replace, ft_strlen(replace) + 1);
	ft_strlcpy((tmp + (substr - (*str) + ft_strlen(replace))), (substr + \
	ft_strlen(find)), ft_strlen(*str) - (substr - *str) - ft_strlen(find) + 1);
	free(*str);
	*str = tmp;
}
