# 1. set variables

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes

SRCS = src/ft_atoi.c \
	src/ft_bzero.c \
	src/ft_calloc.c \
	src/ft_isalnum.c \
	src/ft_isalpha.c \
	src/ft_isascii.c \
	src/ft_isdigit.c \
	src/ft_isprint.c \
	src/ft_memchr.c \
	src/ft_memcmp.c \
	src/ft_memcpy.c \
	src/ft_memmove.c \
	src/ft_memset.c \
	src/ft_split_bonus.c \
	src/ft_strchr.c \
	src/ft_strdup.c \
	src/ft_strjoin_bonus.c \
	src/ft_strlcat.c \
	src/ft_strlcpy.c \
	src/ft_strlen.c \
	src/ft_strncmp.c \
	src/ft_strndup.c \
	src/ft_strnstr.c \
	src/ft_strrchr.c \
	src/ft_substr_bonus.c \
	src/ft_tolower.c \
	src/ft_toupper.c

OBJS = $(SRCS:.c=.o)

# Compilation rules

%.o: %.c
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

.PHONY: all clean fclean re
