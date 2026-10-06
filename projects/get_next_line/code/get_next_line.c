/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 18:43:47 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/06 12:37:23 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *rest)
{
	int		i;
	size_t	bytesread;
	char	buffer[BUFFER_SIZE + 1];

	while (bytesread == BUFFER_SIZE)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		buffer[bytesread] = '\0';
		file = ft_strjoin(file, buffer);
	}

	return (file
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (!rest)
		file = ft_calloc(1);
	line = read_line(fd, rest);

}
