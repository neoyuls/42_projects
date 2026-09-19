#include "libft.h"

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(2, "Too many or to few arguments\n", 28);
		return (1);
	}
	char *trimmed = ft_strtrim(av[1], av[2]);
	write (1, "input:\n", 7);
	write(1, av[1], ft_strlen(av[1]));
	write(1, "\n", 1);
	write (1, "To be trimmed:\n", 15);
	write(1, av[2], ft_strlen(av[2]));
	write(1, "\n", 1);
	write(1, "Output:\n", 9);
	write(1, trimmed, ft_strlen(trimmed));
	free(trimmed);
	return(0);
}
