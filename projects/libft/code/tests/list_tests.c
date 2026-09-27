/* ************************************************************************** */
/*                                                                            */
/*   list_tests.c                                                             */
/*                                                                            */
/*                                                                            */
/*   Harness for the list functions: lstnew, add, size, last, map, clear.     */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s", (char *)lst->content);
		if (lst->next)
			printf(" -> ");
		lst = lst->next;
	}
	printf("\n");
}

static void	free_list(t_list *lst)
{
	t_list	*next;

	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
}

static void	*reverse_string(void *content)
{
	char   *copy;
	size_t   len;
	size_t   i;
	char   tmp;

	copy = ft_strdup((char *)content);
	if (!copy)
		return (NULL);
	len = ft_strlen(copy);
	i = 0;
	while (i < len / 2)
	{
		tmp = copy[i];
		copy[i] = copy[len - 1 - i];
		copy[len - 1 - i] = tmp;
		i++;
	}
	return (copy);
}

static void	del_content(void *content)
{
	free(content);
}

int	main(int ac, char **av)
{
	t_list	*lst;
	t_list	*lst2;
	int i;

	if (ac <= 1)
	{
		write(2, "Error. Insert at least 1 parameter\n", 35);
		return (1);
	}
	lst = NULL;
	i = 1;
	while (i < ac)
	{
		ft_lstadd_back(&lst, ft_lstnew(av[i]));
		i++;
	}
	printf("size: %u\n", ft_lstsize(lst));
	printf("list:	");
	print_list(lst);
	printf("last:	%s\n", (char *)ft_lstlast(lst)->content);
	lst2 = ft_lstmap(lst, reverse_string, del_content);
	printf("list 2:	");
	print_list(lst2);
	ft_lstclear(&lst2, del_content);
	free(lst2);
	free_list(lst);
	return (0);
}
