# include "libft.h"
# include <stdio.h>
# include <string.h>

int main(int ac, char **av)
{
	if (ac != 3)
	{
		write (2, "Error!\n", 6);
		return (2);
	}

	printf("my function:		%s\n", (char *)ft_memmove(av[1] + 2, av[1], atoi(av[2])));
	printf("string.h function:	%s\n", (char *)memmove(av[1] + 2, av[1], atoi(av[2])));
	return 0;
}
