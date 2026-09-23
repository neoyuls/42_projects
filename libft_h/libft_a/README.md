*This project has been created as part of the 42 curriculum by jvernon.*
# libft: A C library including general purpose functions.

## Description 

This project consists of a library of various utility functions written in the C programming language. Function declarations live in `includes/libft.h`, and the code for the functions themselves lives in the `srcs/` directory.

| Name | Category | Arguments | Return value | Brief description |
| --- | --- | --- | --- | --- |
| `ft_isalpha` | Character classification | `int c` | Non-zero if `c` is alphabetic, `0` otherwise | |
| `ft_isdigit` | Character classification | `int c` | Non-zero if `c` is a digit, `0` otherwise | |
| `ft_isalnum` | Character classification | `int c` | Non-zero if `c` is alphanumeric, `0` otherwise | |
| `ft_isascii` | Character classification | `int c` | Non-zero if `c` is a valid ASCII character, `0` otherwise | |
| `ft_isprint` | Character classification | `int c` | Non-zero if `c` is printable, `0` otherwise | |
| `ft_strlen` | String manipulation | `const char *s` | Number of characters in `s`, excluding the terminating `'\0'` | |
| `ft_memset` | Memory management | `void *s`, `int c`, `size_t n` | Pointer to `s` | |
| `ft_bzero` | Memory management | `void *s`, `size_t n` | Nothing | |
| `ft_memcpy` | Memory management | `void *dest`, `const void *src`, `size_t n` | Pointer to `dest` | |
| `ft_memmove` | Memory management | `void *dest`, `const void *src`, `size_t n` | Pointer to `dest` | |
| `ft_strlcpy` | String manipulation | `char *dest`, `const char *src`, `size_t size` | Total length of the string it tried to create (length of `src`) | |
| `ft_strlcat` | String manipulation | `char *dest`, `const char *src`, `size_t size` | Total length of the string it tried to create (initial `dest` length + `src` length) | |
| `ft_toupper` | Character conversion | `int c` | Uppercase equivalent of `c`, or `c` if not a lowercase letter | |
| `ft_tolower` | Character conversion | `int c` | Lowercase equivalent of `c`, or `c` if not an uppercase letter | |
| `ft_strchr` | String manipulation | `const char *s`, `int c` | Pointer to the first occurrence of `c` in `s`, `NULL` if not found | |
| `ft_strrchr` | String manipulation | `const char *s`, `int c` | Pointer to the last occurrence of `c` in `s`, `NULL` if not found | |
| `ft_strncmp` | String manipulation | `const char *s1`, `const char *s2`, `size_t n` | `0` if the first `n` bytes match, otherwise the difference between the first differing bytes | |
| `ft_memchr` | Memory management | `const void *s`, `int c`, `size_t n` | Pointer to the first matching byte, `NULL` if not found | |
| `ft_memcmp` | Memory management | `const void *s1`, `const void *s2`, `size_t n` | `0` if the first `n` bytes match, otherwise the difference between the first differing bytes | |
| `ft_strnstr` | String manipulation | `const char *big`, `const char *little`, `size_t n` | Pointer to the first occurrence of `little` in `big` (within `n` bytes), `NULL` if not found | |
| `ft_atoi` | Data parsing | `const char *nbr` | The `int` value represented by `nbr` | |
| `ft_calloc` | Memory management | `size_t n`, `size_t size` | Pointer to zero-initialised allocated memory, `NULL` on failure | |
| `ft_strdup` | String manipulation | `const char *s` | Newly allocated copy of `s`, `NULL` on failure | |
| `ft_substr` | String manipulation | `char const *s`, `unsigned int start`, `size_t len` | Newly allocated substring of `s`, `NULL` on failure | |
| `ft_strjoin` | String manipulation | `char const *s1`, `char const *s2` | Newly allocated concatenation of `s1` and `s2`, `NULL` on failure | |
| `ft_strtrim` | String manipulation | `char const *s1`, `char const *set` | Newly allocated copy of `s1` with leading/trailing `set` characters removed, `NULL` on failure | |
| `ft_split` | String manipulation | `char const *s`, `char c` | `NULL`-terminated array of newly allocated strings, `NULL` on failure | |
| `ft_itoa` | Data parsing | `int n` | Newly allocated string representation of `n`, `NULL` on failure | |
| `ft_strmapi` | String manipulation | `char const *s`, `char (*f)(unsigned int, char)` | Newly allocated string with `f` applied to each character, `NULL` on failure | |
| `ft_striteri` | String manipulation | `char *s`, `void (*f)(unsigned int, char *)` | Nothing | |
| `ft_putchar_fd` | Output | `char c`, `int fd` | Nothing | |
| `ft_putstr_fd` | Output | `char *s`, `int fd` | Nothing | |
| `ft_putendl_fd` | Output | `char *s`, `int fd` | Nothing | |
| `ft_putnbr_fd` | Output | `int n`, `int fd` | Nothing | |
| `ft_lstnew` | Linked list | `void *content` | Pointer to the newly allocated node, `NULL` on failure | |
| `ft_lstadd_front` | Linked list | `t_list **lst`, `t_list *new` | Nothing | |
| `ft_lstadd_back` | Linked list | `t_list **lst`, `t_list *new` | Nothing | |
| `ft_lstsize` | Linked list | `t_list *lst` | Number of nodes in the list | |
| `ft_lstlast` | Linked list | `t_list *lst` | Pointer to the last node, `NULL` if the list is empty | |
| `ft_lstdelone` | Linked list | `t_list *lst`, `void (*del)(void *)` | Nothing | |
| `ft_lstclear` | Linked list | `t_list **lst`, `void (*del)(void *)` | Nothing | |
| `ft_lstiter` | Linked list | `t_list *lst`, `void (*f)(void *)` | Nothing | |
| `ft_lstmap` | Linked list | `t_list *lst`, `void *(*f)(void *)`, `void (*del)(void *)` | Pointer to the newly allocated list, `NULL` on failure | |

## Instructions

 The library is compiled into object files(`.o`) and an archive(`libft.a`) file through the GNU make command, which derives it's instructions from `Makefile`. This makefile consists firstly of the setting of variables, including the name of the compiled binary, an alias for the compiler to be used, flags for the compiler to be used, paths to the source files, and destinations for compiled object files. After setting the variables, the makefile establishes the rules the compiler will follow upon invocation of `make`.

After compilation, in order to use the library's functions, compilation must follow this format
```sh
cc [flags] [path/to/targets] [path/to/libft.a] [other parameters such as -o]
```
It is important to note that the order of compiler targets does matter. During compilation, the linker reads input once, **left to right**, saving *undefined symbols* (in this case referring to the functions in libft.h)

## Resources

The main resource used to derive function prototypes and explanations of how the aforementioned functions work are the GNU man-pages; accessed through the `man` command:
```sh
man [insert function here]
# in some cases the section of the manual must be specified:
man 2 open
# 'man open' opens the manual for the shell command open
```
In order to understand syntax and concepts, the book *The C Programming Language: Second Edition* was used as a reference.

### Citation

> Kernighan, B. W., & Ritchie, D. M. (1988). *The C Programming Language* (2nd ed.). Prentice Hall. ISBN 0-13-110362-8.
>
> Full text available in this repository: [`books/C_Book_2nd.pdf`](../../books/C_Book_2nd.pdf)
