#include "libft.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(2, "Insert 2 parameters.\n", 21);
		return (1);
	}
	int fd = open(av[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	ft_putnbr_fd(atoi(av[2]), fd);
	write(fd, "\n", 1);
	return (0);
}
