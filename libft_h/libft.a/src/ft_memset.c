/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42.es>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 03:21:00 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/20 03:31:21 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *s, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <unistd.h>

int	main(void)
{
	char str[20] = "hola bb yo soy yuls";
	unsigned int off = 15;
	int c = 35;

	write(1, "Before:", 7);
	for (int i = 0; str[i]; i++)
		write(1, &str[i], 1);
	write(1, "\n", 1);
	write(1, "After:", 6);
	ft_memset(str, c, off);
	for (int j = 0; str[j]; j++)
		write(1, &str[j], 1);
	write(1, "\n", 1);
	return (0);
}
*/
