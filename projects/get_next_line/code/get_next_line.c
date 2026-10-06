/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 18:43:47 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/06 17:22:27 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*get_rest(char *rest)
{
	char	*line;
	int		i;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\0')
	{
		free(rest);
		return (NULL);
	}
	line = ft_substr(rest, i, ft_strlen(rest) - 1 + 1);
	if (!line)
		return (NULL);
	free(rest);
	return (line);
}

char	*read_file(int fd, char *rest)
{
	ssize_t	bytesread;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	*buffer = '\0';
	bytesread = 1;
	while (!(ft_strchr(buffer, '\n')) && bytesread >= 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytesread] = '\0';
		rest = ft_strjoin(rest, buffer);
	}
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (!rest)
		rest = ft_strdup("");
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// i = 0;
	line = NULL;
	rest = read_file(fd, rest);
	if (!rest)
		return (NULL);
	if (*rest)
	{
		line = ft_strdup(rest);
		if (!line)
			return (NULL);
	}
	rest = get_rest(rest);
	return (line);
}

#include <fcntl.h>

int	main()
{
	int fd = open("get_next_line.h", O_RDONLY);
	char *line;
	//int i = 0;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
