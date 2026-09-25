# Makefile for libft.a
NAME = libft.a
CC = cc
CFLAGS = -Werror -Wextra -Wall

SRC = srcs/ft_putchar.c \
	srcs/ft_putstr.c \
	srcs/ft_strcmp.c \
	srcs/ft_strlen.c \
	srcs/ft_swap.c

OBJS = $(SRC:.c=.o)

# Compilation Rules

srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -I includes -c $< -o $@

# Targets

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
