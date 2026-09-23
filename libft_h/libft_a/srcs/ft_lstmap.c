/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 07:02:50 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/23 07:51:55 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*node;
	void	*buf;

	if (!lst || !f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		buf = f(lst->content);
		node = ft_lstnew(buf);
		if (!node)
		{
			del(buf);
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, node);
		lst = lst->next;
	}
	return (first);
}
