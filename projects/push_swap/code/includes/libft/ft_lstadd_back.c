/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 00:39:48 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/11 06:26:55 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newlist)
{
	t_list	*last;

	if (!lst || !newlist)
		return ;
	if (!*lst)
	{
		*lst = newlist;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = newlist;
}
