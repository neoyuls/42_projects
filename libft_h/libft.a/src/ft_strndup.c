/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:54:30 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/28 14:45:22 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Oops, made the wrong function (lol)
// will keep this here but will exclude from assignment repo
char	*ft_strndup(const char *s, unsigned int n)
{
	char			*new;
	unsigned int	i;

	i = 0;
	new = malloc(sizeof(char) * (n + 1));
	if (!new)
		return ((void *)0);
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

	char	*mine;
	char	*ref;

	mine = ft_strndup(av[1], atoi(av[2]));
	ref = strndup(av[1], atoi(av[2]));
	printf("My function:		%s \n", mine);
	printf("String.h function:	%s \n", ref);
	free(mine);
	free(ref);
	return (0);
}
*/
