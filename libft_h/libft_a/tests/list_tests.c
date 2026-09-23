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

int	main(void)
{
	t_list	*lst;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew("one"));
	ft_lstadd_back(&lst, ft_lstnew("two"));
	ft_lstadd_front(&lst, ft_lstnew("zero"));

	printf("size: %u\n", ft_lstsize(lst));
	printf("list: ");
	print_list(lst);
	printf("last: %s\n", (char *)ft_lstlast(lst)->content);

	free_list(lst);
	return (0);
}
