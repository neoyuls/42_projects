/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:10:17 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/21 17:47:28 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// VERY UNFINISHED, WILL DO LATER
// I DONT LIKE THIS FUNCTION
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (size);
	while (i < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (size >= i)
		dest[i] = '\0';
	return (i);
}
