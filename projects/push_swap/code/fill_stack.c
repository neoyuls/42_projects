/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 05:40:32 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/11 05:43:39 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack(int value, int index)
{
	t_stack	*stack;

	stack->number = value;
	stack->index = index;
	stack->next = NULL;
	return(stack);
}
