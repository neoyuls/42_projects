/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 22:36:31 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/27 01:08:04 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*found;

	found = (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			found = (char *)s;
		}
		s++;
	}
	if (found != (NULL))
		return (found);
	if (*s == 0)
		return ((char *)s);
	return (NULL);
}

/*
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("ERROR");
		return 1;
	}
	char c = *ft_strrchr(av[1], 65);
	printf("found %c\n", c);
	return 0;
}
*/
