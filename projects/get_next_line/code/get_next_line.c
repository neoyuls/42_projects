/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 18:43:47 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/06 14:51:29 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
char	*get_line(char *rest, char *line)
{
	int	i;

	i = 0;
	while (rest[i] != '\n' && rest[i])
		i++;
	line = ft_substr(rest, 0, i);
	rest = ft_strchr(rest, '\n');
	return (line);
}

char	*read_file(int fd, char *rest)
{
	ssize_t	bytesread;
	char	*buffer;
	char	*store;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytesread = 1;
	while (bytesread > 0 && !ft_strchr(rest, '\n'))
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (NULL);
		buffer[bytesread] = '\0';
		store = ft_strjoin(rest, buffer);
		free(rest);
		rest = store;
	}
	free(buffer);
	free(store);
	return (rest);
}
*/

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (!rest)
		rest = ft_strdup("");
	
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int fd = open("get_next_line.c", O_RDONLY);
	char *line;
	//int i = 0;

	line = get_next_line(fd);
	printf("%s\n", line);
	return (0);
}
