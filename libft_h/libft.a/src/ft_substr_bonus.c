/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 17:17:04 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/28 18:35:04 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	sub = malloc(sizeof(char) * len + 1);
	if ((!sub))
		return (NULL);
	while (s[start + i] && i <= (unsigned int)len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/* TESTING 
#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	char *str1 = ft_substr(av[1], (unsigned int)atoi(av[2]), (size_t)atoi(av[3]));
	printf("original string: %s \n function result: %s\n", av[1], str1);
	free(str1);
	return (0);
}
*/
