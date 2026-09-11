# Makefile for libft.a
NAME = libft.a
CC = cc
CFLAGS = -Werror -Wextra -Wall
INCLUDES = -Iincludes

SRC = src/ft_putchar.c\
	src/ft_putstr.c\
	src/ft_strcmp.c\
	src/ft_strlen.c\
	src/ft_swap.c

OBJS = $(SRC:.c=.o)

# Compilation Rules

%.o: %.c includes/libft.h
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Targets

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)
clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONE: all clean fclean re
