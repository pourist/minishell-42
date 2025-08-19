/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:45:11 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/15 13:14:12 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		ctr;
	t_list	*nxt;

	ctr = 1;
	if (!lst)
		return (0);
	if (!(lst->next))
		return (ctr);
	nxt = lst->next;
	while (nxt)
	{
		nxt = nxt->next;
		ctr++;
	}
	return (ctr);
}
