/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:34:42 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/14 15:42:58 by jvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	open_read(char *path)
{
	int		fd;
	char	buf[1024];
	ssize_t	bytesread;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	bytesread = read(fd, buf, sizeof(buf));
	while (bytesread > 0)
	{
		write (1, buf, bytesread);
		bytesread = read(fd, buf, sizeof(buf));
	}
	close(fd);
	if (bytesread == -1)
		return (0);
	return (1);
}
