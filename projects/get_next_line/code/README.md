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
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -o gnl
```

### Buffer size

`BUFFER_SIZE` (default `42`) is defined in `get_next_line.h` and controls how
many bytes each `read()` call fetches. To override it at compile time with
`-D BUFFER_SIZE=n`, remove or guard the `#define` in the header first —
`tests/run_tests.sh` does this automatically on a scratch copy.

## Project structure

```
├── get_next_line.c        # get_next_line(), read_file(), get_rest()
├── get_next_line.h        # prototypes, BUFFER_SIZE
├── get_next_line_utils.c  # ft_strdup / ft_strchr / ft_strjoin / ft_substr / ft_strlen
└── tests/
    ├── test_gnl.c         # fork-protected harness, diffs output vs POSIX getline()
    └── run_tests.sh       # builds & runs the harness across BUFFER_SIZEs + ASan/UBSan
```

## Testing

```sh
./tests/run_tests.sh
```

The harness checks each case in a forked child (a crash only fails that case)
and compares every returned line against `getline()`:

- edge cases: empty file, lone `\n`, missing final newline, blank/CRLF lines
- stress: 5000-char line, line of exactly `BUFFER_SIZE`, 300 short lines
- repeated calls after EOF, invalid fds, interleaved multi-fd reads

Environment knobs: `BUFFER_SIZES="1 2 3 42 1024"`, `SKIP_SAN=1`, `SAN_BS=42`,
`DETECT_LEAKS=1`, `CC`, `SAN_FLAGS`.

### Current status

- ✅ All single-fd cases pass for `BUFFER_SIZE` = 1, 2, 3, 42, 1024, clean under
  AddressSanitizer/UBSan.
- ❌ Interleaved multi-fd reads (bonus): the single shared static stash mixes
  data between fds — per-fd storage is not implemented yet.
