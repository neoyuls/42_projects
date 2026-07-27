/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 01:59:47 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/27 02:45:07 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *big, const char *little, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < n && big[i] != 0)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j])
			{
				j++;
			}
			if (little[j] == '\0')
			{
				big += i;
				return ((char *)big);
			}
		}
		i++;
	}
	return (NULL);
}
/*
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		write(2, "Error!\n", 7);
		return 1;
	}
	printf("my function: %s\n", ft_strnstr(av[1], av[2], atoi(av[3])));
}
*/
