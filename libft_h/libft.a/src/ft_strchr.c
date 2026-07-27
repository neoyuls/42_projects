/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 12:33:38 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/26 22:33:57 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	tofind;

	if (c < 0 || c > 255)
		return ((void *)0);
	tofind = (char)c;
	while (*s != '\0')
	{
		if (*s == tofind)
			return ((char *)s);
		s++;
	}
	return ((void *)0);
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
	char c = *ft_strchr(av[1], 65);
	printf("found %c\n", c);
	return 0;
}
*/
