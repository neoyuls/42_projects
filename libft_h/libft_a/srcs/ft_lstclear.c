/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 04:12:44 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/23 06:05:47 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*nxt;

	if (!lst || !(*lst))
		return ;
	nxt = *lst;
	while (nxt->next)
	{
		node = nxt;
		del(node->content);
		nxt = nxt->next;
		free(node);
	}
	free(nxt);
	*lst = NULL;
}
