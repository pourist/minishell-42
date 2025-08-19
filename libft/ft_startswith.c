/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startswith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:44:13 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/02/23 15:04:20 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_startswith(char *s1, char *s2)
{
	if (!ft_strncmp(s1, s2, ft_strlen(s2)))
		return (1);
	else
		return (0);
}
