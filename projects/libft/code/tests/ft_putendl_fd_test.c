/* ************************************************************************** */
/*                                                                            */
/*   ft_putendl_fd_test.c                                                     */
/*                                                                            */
/*                                                                            */
/*   Harness for ft_putendl_fd: writes a string plus newline to a file.       */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "Insert 2 parameters.\n", 21);
		return (1);
	}
	ssize_t bytesread;
	int fd = open(av[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd(av[2], fd);
	lseek(fd, 0, SEEK_SET);
	write(1, "File contents:", 14);
	char *buf = malloc(ft_strlen(av[2]) + 1);
	while ((bytesread = read(fd, buf, ft_strlen(av[2]) + 1)) > 0)
		write (1, buf, bytesread);
	close(fd);
	free(buf);
	return (0);
}
