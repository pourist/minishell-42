/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:14:54 by jstrozyk          #+#    #+#             */
/*   Updated: 2023/11/15 13:28:56 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nxt;

	if (!*lst)
		return ;
	nxt = (*lst)->next;
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
	ft_lstclear(&nxt, del);
}
