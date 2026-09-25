/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   just a test of how much space different structs occupy in memory         */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct list_node
{
	void				*content;
	struct list_node	*next;
}						t_list_node;

typedef struct stringlist
{
	char	*str1;
	char	*str2;
	char	*str3;
}			t_strlst;

struct strlst
{
	char	*str1;
	char	*str2;
	char	*str3;
};

struct mixed
{
	double			dbl;
	char			*str;
	double			dbl2;
	char			*otherstr;
	double			dbl3;
	char			*otherstr1;
	double			dbl4;
	char			*otherstr2;
	double			dbl5;
	char			*otherstr3;
	double			dbl6;
	char			*otherstr4;
};

struct	sorted
{
	char			*otherstr1;
	char			*otherstr2;
	char			*otherstr3;
	char			*otherstr4;
	char			*otherstr;
	char			*str;
	double			dbl2;
	double			dbl3;
	double			dbl4;
	double			dbl5;
	double			dbl6;
	double			dbl;
};

typedef struct	mixed_and_named
{
	double			dbl;
	char			*str;
	double			dbl2;
	char			*otherstr;
}					t_MaN;

typedef struct	sorted_and_named
{
	double			dbl;
	double			dbl2;
	char			*str;
	char			*otherstr;
}					t_SaN;

int	main(void)
{
	printf("%d\n",(int)sizeof(t_list_node));
	printf("%d\n",(int)sizeof(t_strlst));
	printf("%d\n",(int)sizeof(struct strlst));
	printf("%d\n",(int)sizeof(struct mixed));
	printf("%d\n",(int)sizeof(struct sorted));
	printf("%d\n",(int)sizeof(t_MaN));
	printf("%d\n",(int)sizeof(t_SaN));
}
