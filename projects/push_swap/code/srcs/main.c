/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 05:37:05 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/11 06:30:09 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *stack_a;
	int		i;

	if (ac <= 1)
		return (1);
	i = 0;
	while (i++ < ac)
		*stack_a = fill_stack(ft_atoi(av[i]), i - 1);
	return (0);
}
