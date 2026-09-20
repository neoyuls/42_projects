#include "libft.h"

void	iter(unsigned int i, char* s)
{
	*s += i;
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Error! Introduce 2 parameters\n", 30);
		return (1);
	}
	size_t i = 0;
	while (av[1][i])
	{
		write(1, &av[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	write(1, "\n", 1);
	ft_striteri(av[1], iter);
	i = 0;
	while (av[1][i])
	{
		write(1, &av[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
