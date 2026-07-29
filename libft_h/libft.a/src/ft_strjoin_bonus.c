/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 19:54:55 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/28 20:27:05 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_allocate(const char *s1, const char *s2)
{
	char			*joined;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	joined = malloc(sizeof(char) * (i + j + 1));
	if (!joined)
		return (NULL);
	return (joined);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*joined;
	unsigned int	i;

	i = 0;
	joined = ft_allocate(s1, s2);
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		joined[i] = *s2;
		i++;
		s2++;
	}
	joined[i] = '\0';
	return (joined);
}

/* TESTING
#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write (2, "Error\n", 6);
		return (1);
	}
	char *s = ft_strjoin(av[1], av[2]);
	printf("for inputs: %s and %s\n", av[1], av[2]);
	printf("result: %s\n", s);
	free(s);
	return (0);
}
*/
