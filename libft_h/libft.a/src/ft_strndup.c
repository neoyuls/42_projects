/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neoyuls <neoyuls@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:54:30 by neoyuls           #+#    #+#             */
/*   Updated: 2026/07/28 14:45:22 by neoyuls          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Oops, made the wrong function (lol)
// will keep this here but will exclude from assignment repo
char	*ft_strndup(const char *s, unsigned int n)
{
	char			*new;
	unsigned int	i;

	i = 0;
	new = malloc(sizeof(char) * (n + 1));
	if (!new)
		return ((void *)0);
	while (i < n && s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
