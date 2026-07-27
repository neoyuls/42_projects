/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:54:30 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/27 13:10:34 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(const char *s, unsigned int n)
{
	char			*new;
	unsigned int	i;

	i = 0;
	new = malloc(sizeof(char) * n);
	while (i < n && s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

/* TESTING
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "error!\n", 7);
		return (1);
	}

	printf("My function:		%s \n", ft_strndup(av[1], atoi(av[2])));
	printf("String.h function:	%s \n", strndup(av[1], atoi(av[2])));
	return (0);
}
*/
