/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:45:38 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/28 15:03:25 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if ((!str))
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	char *str = ft_strdup(av[1]);
	printf("My function: %s\n", str);
	char *str2 = strdup(av[1]);
	printf("string.h function: %s\n", str2);
	free(str);
	free(str2);
	return 0;
}
*/
