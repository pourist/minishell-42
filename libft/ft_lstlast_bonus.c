/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:56:53 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/15 13:14:38 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*nxt;

	if (!lst)
		return (NULL);
	if (!(lst->next))
		return (lst);
	nxt = lst->next;
	while (nxt->next)
		nxt = nxt->next;
	return (nxt);
}
