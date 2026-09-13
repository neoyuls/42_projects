# 1. set variables

NAME = ft_display_file
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/main.c \
		src/open_read.c

OBJS = $(SRCS:.c=.o)

# Compilation rules

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Targets

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
