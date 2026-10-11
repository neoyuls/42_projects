*This project has been created as part of the 42 curriculum by jvernon*

# get_next_line

A C function that reads a file descriptor **one line at a time**, returning a newly
allocated string on each call. Written from scratch using only `read`, `malloc`
and `free` (42 Málaga).

```c
char *get_next_line(int fd);
```

## Behavior

| Situation | Return value |
|---|---|
| Line available | Heap-allocated line, **including the trailing `\n`** (if the line has one) |
| EOF, nothing left to read | `NULL` |
| Error (`fd < 0`, `BUFFER_SIZE <= 0`, failed `read`) | `NULL` |

- The last line is returned even without a terminating newline.
- Repeated calls after EOF keep returning `NULL`.
- The caller is responsible for `free()`ing every returned line.
- State between calls is kept in a `static` leftover buffer.

## How it works

1. **`read_file()`** — appends `BUFFER_SIZE`-sized chunks to a static stash
   (`rest`) until it contains a `\n` or `read()` reaches EOF/error.
2. **`get_rest()`** — splits the stash at the first `\n`: the line (newline
   included) is returned, the remainder stays in the stash for the next call.
3. Helpers in `get_next_line_utils.c`: `ft_strdup`, `ft_strchr`, `ft_strjoin`,
   `ft_substr`, `ft_strlen`.

## Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int		fd = open("file.txt", O_RDONLY);
	char	*line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}
```

```sh
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c [main_function] -o gnl
```

### Buffer size

`BUFFER_SIZE` (default `42`) controls how many bytes each `read()` call
fetches. The `#define` in the header is guarded by `#ifndef`, so it can be
overridden directly at compile time:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 main.c get_next_line.c get_next_line_utils.c [main_function] -o gnl
```

## Bonus: multiple file descriptors

The bonus version keeps **one stash per file descriptor**, so calls on
different fds can be interleaved without mixing data:

```c
static char	*rest[ARRAY_SIZE];	/* ARRAY_SIZE = 1024 */
```

- `rest[fd]` holds the leftover for each fd independently.
- An fd's stash is freed and reset to `NULL` once it reaches EOF, so memory
  is released progressively instead of all at once.
- Reads from fds `>= ARRAY_SIZE` are rejected.

```sh
cc -Wall -Wextra -Werror main.c get_next_line_bonus.c get_next_line_utils_bonus.c [main_function] -o gnl_bonus
```

## Project structure

```
├── get_next_line.c              # get_next_line(), read_file(), get_rest()
├── get_next_line.h              # prototypes, BUFFER_SIZE
├── get_next_line_utils.c        # ft_strdup / ft_strchr / ft_strjoin / ft_substr / ft_strlen
├── get_next_line_bonus.c        # multi-fd version: get_next_line(), read_file(), get_rest()
├── get_next_line_bonus.h        # bonus prototypes, BUFFER_SIZE, ARRAY_SIZE
└── get_next_line_utils_bonus.c  # bonus helpers
```
## Resources

Several different resources were consulted whilst working on this project; namely:

- `man` pages for `open` and `read`, for understanding mechanics behind obtaining and reading from file descriptors, as well as arguments which are passed to these functions
- 42 norm and get_next_line subject

### AI usage

LLMs were used for tedious formatting tasks, generating parts of the README.md, and for the final rounds of testing before finishing the program, in order to find edge cases to account for in the code.

The LLMs used were deepseek V4.1 flash and Kimi K3. None of the code or logic behind the code was written by AI.
