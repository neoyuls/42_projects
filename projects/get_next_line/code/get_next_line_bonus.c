/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 18:43:47 by jvernon           #+#    #+#             */
/*   Updated: 2026/10/11 03:41:43 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line_bonus.h"

char	*get_rest(char **rest)
{
	char	*line;
	char	*separator;
	char	*temp;

	separator = ft_strchr(*rest, '\n');
	if (separator)
		line = ft_substr(*rest, 0, separator - *rest + 1);
	else
		line = ft_strdup(*rest);
	if (!line)
	{
		free(*rest);
		*rest = NULL;
		return (NULL);
	}
	if (separator)
		temp = ft_strdup(separator + 1);
	else
		temp = NULL;
	free (*rest);
	*rest = temp;
	return (line);
}

static char	*free_all(char *buffer, char *rest)
{
	free(buffer);
	free(rest);
	return (NULL);
}

static char	*join_free(char *rest, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(rest, buffer);
	free(rest);
	return (temp);
}

char	*read_file(int fd, char *rest)
{
	ssize_t	bytesread;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free_all(NULL, rest));
	bytesread = 1;
	*buffer = '\0';
	while (bytesread > 0 && !ft_strchr(buffer, '\n'))
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (free_all(buffer, rest));
		buffer[bytesread] = '\0';
		rest = join_free(rest, buffer);
		if (!rest)
			return (free_all(buffer, NULL));
	}
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest[ARRAY_SIZE];
	char		*line;

	if (!rest[fd])
		rest[fd] = ft_strdup("");
	if (fd >= ARRAY_SIZE || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	rest[fd] = read_file(fd, rest[fd]);
	if (!rest[fd] || *rest[fd] == '\0')
	{
		free(rest[fd]);
		rest[fd] = NULL;
		return (NULL);
	}
	line = get_rest(&rest[fd]);
	return (line);
}
