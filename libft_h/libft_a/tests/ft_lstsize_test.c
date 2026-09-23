/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 03:46:32 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/23 04:01:32 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac < 1)
	{
		write(2, "Introduce 1 or more arguments\n", 30);
		return (1);
	}
	unsigned int	i = 0;
	t_list			**lst;
	t_list			*node;

	lst = malloc(sizeof(*lst));
	node = NULL;
	*lst = node;
	while (i < (unsigned int)ac)
	{
		node = ft_lstnew(av[i]);
		i++;
	}
	printf("list size: %d\n", ft_lstsize(*lst));
	free(lst);
}
