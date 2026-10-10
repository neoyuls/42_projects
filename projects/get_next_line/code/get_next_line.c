/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 18:43:47 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/10 19:42:25 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*get_rest(char **rest)
{
	char	*line;
	char	*separator;
	char	*temp;

	separator = ft_strchr(*rest, '\n');
	if (!separator)
	if (separator)
		line = ft_substr(*rest, 0, separator - *rest + 1);
	else
		line = *rest;
	if (!line)
	{
		free(*rest);
		*rest = NULL;
		return (NULL);
	}
	temp = ft_strdup(separator + 1);
	free (*rest);
	*rest = temp;
	return (line);
}

char	*read_file(int fd, char *rest)
{
	ssize_t	bytesread;
	char	*buffer;
	char	*temp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	*buffer = '\0';
	bytesread = 1;
	while (!(ft_strchr(buffer, '\n')) && bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytesread] = '\0';
		temp = ft_strjoin(rest, buffer);
		free(rest);
		if (!temp)
		{
			free(buffer);
			return (NULL);
		}
		rest = temp;
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
	line = NULL;
	rest = read_file(fd, rest);
	if (!rest)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	line = get_rest(&rest);
	return (line);
}

#include <fcntl.h>

int	main()
{
//	int fd = open("get_next_line.c", O_RDONLY);
	int fd = 0;
	char *line;
	int i = 0;

	// while ((line = get_next_line(fd)) != NULL)
	while (i < 111)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	return (0);
}
