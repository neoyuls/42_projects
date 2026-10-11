/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 07:33:15 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/11 07:54:12 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*pushed;
	t_stack	*temp;

	if (!stack_a || !stack_b)
		return (NULL);
	temp = *stack_b;
	*stack_b = temp->next;
	pushed = temp;
	pushed->next = *stack_a;
	return(pushed);
}

t_stack	*push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*pushed;
	t_stack	*temp;

	if (!stack_a || !stack_b)
		return (NULL);
	temp = *stack_a;
	*stack_a = temp->next;
	pushed = temp;
	pushed->next = *stack_b;
	return(pushed);
}
