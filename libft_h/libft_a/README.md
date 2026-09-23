*This project has been created as part of the 42 curriculum by jvernon.*
# libft: A C library including general purpose functions.

## Description 

This project consists of a library of various utility functions written in the C programming language. Function declarations live in `includes/libft.h`, and the code for the functions themselves lives in the `srcs/` directory.

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
