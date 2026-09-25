/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 04:12:44 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/25 02:55:25 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*nxt;

	if (!lst || !(*lst) || !del)
		return ;
	nxt = *lst;
	while (nxt)
	{
		node = nxt->next;
		ft_lstdelone(nxt, del);
		nxt = node;
	}
	*lst = NULL;
}
