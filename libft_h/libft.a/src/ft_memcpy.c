/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:42:15 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/20 19:57:01 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// REVISIT LATER
void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned int	i;
	unsigned char	*source;
	unsigned char	*destination;

	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
/*
#include <unistd.h>

int	main(void)
{
	char str[20] = "hola bb yo soy yuls";
	char dest[20];
	unsigned int off = 15;

	write(1, "Before:", 7);
	for (int i = 0; str[i]; i++)
		write(1, &str[i], 1);
	write(1, "\n", 1);
	write(1, "After:", 6);
	ft_memcpy(dest, str, off);
	for (int j = 0; dest[j]; j++)
		write(1, &dest[j], 1);
	write(1, "\n", 1);
	return (0);
}
*/
