/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 21:56:52 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/21 11:57:41 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	ft_lstnew(void *content)
{
	struct	s_list 	next;

	next.content = content;
	next.next.next = NULL;
	return(next);
}
