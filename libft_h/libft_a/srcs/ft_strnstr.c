/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 01:59:47 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/14 02:40:32 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < n && big[i] != 0)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && i + j < n)
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
	return ((void *)0);
}
