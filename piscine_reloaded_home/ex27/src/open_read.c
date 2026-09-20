/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvernon <jvernon@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 21:32:48 by jvernon           #+#    #+#             */
/*   Updated: 2026/09/13 02:33:21 by jvernon          ###   ########.fr       */
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
	while ((bytesread = read(fd, buf, sizeof(buf) - 1)) > 0)
	{
		buf[bytesread] = '\0';
		write (1, buf, bytesread);
	}
	close(fd);
	return (1);
}
