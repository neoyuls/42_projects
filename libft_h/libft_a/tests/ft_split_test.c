#include "libft.h"

int	main(int ac, char **av)
{
	if (ac > 3)
	{
		write(2, "Too many arguments.\n", 19);
		return (1);
	}
	if (ac < 3)
	{
		write(2, "Too few arguments.\n", 18);
		return (1);
	}
	
	int i = 0;
	char **strarr = ft_split(av[1], av[2][0]);
	while (av[1][i])
	{
		if (av[1][i - 1] == av[2][0])
			i++;
	}
	for (int j = 0; j <= i; j++)
	{
		write(1, strarr[j], ft_strlen(strarr[j]));
	}
	return (0);
}
