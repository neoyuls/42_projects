/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 07:54:24 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/11 08:25:02 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack **a)
{
	t_stack	*temp;

	if (!a || (*a)->next == NULL)
		return ;
	temp = (*a)->next;
	(*a)->next = *a;
	*a = temp;
	(*a)->next 
}
