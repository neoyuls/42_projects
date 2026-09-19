#include "libft.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(2, "Insert 2 parameters.\n", 21);
		return (1);
	}
	int fd = open(av[1], O_WRONLY);
	for (int i = 0; av[2][i]; i++)
	{
		ft_putchar_fd(av[2][i], fd);
	}
	close(fd);
	return (0);
}
