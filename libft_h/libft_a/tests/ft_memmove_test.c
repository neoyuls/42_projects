#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		write(2, "Enter 3 parameters\n", 18);
	}
	printf("Original string: %s\n", av[1]);
	ft_memmove(av[1] + atoi(av[2]), av[1], atoi(av[3]));
	printf("memmove(string.h) output: %s\n", av[1]);
	return 0;
}
