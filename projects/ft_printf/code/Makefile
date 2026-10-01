NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
HEADER = includes/printf.h

SRCS = srcs/ft_printf.c srcs/putnumber.c \
	   srcs/putpointer.c srcs/putstring.c \
	   srcs/putchar_return.c

OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
