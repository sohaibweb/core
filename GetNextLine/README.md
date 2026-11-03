*This activity has been created as part of the 42 curriculum by sabu-msa.*

# get_next_line

## Description

**Goal.** `get_next_line` is a C function that reads from a file descriptor and returns **one line per call**, including the trailing `\n` when there is one. Called in a loop, it reads a whole file (or standard input) line by line. The project teaches static variables, file descriptors, `read(2)` behaviour and dynamic memory management, under the 42 Norm.

**Overview.**

```c
char	*get_next_line(int fd);
```

| Result | Meaning |
|---|---|
| A string | The next line, ending in `\n` (the last line of a file may have none) |
| `NULL` | End of file, or an error (invalid `fd`, `read` failure, allocation failure) |

The returned string is allocated with `malloc`; the caller must `free` it. The only allowed external functions are `read`, `malloc` and `free`. The buffer size is chosen at compile time through `BUFFER_SIZE`, and the function must behave correctly for any positive value.

**Files:** `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`.

## Instructions

**Compilation.** `BUFFER_SIZE` is set with `-D` (the header defaults it to `42` if it is not given):

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

**Usage.** Include `get_next_line.h`, call the function in a loop, and free every returned line:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

**Norm check:** `norminette get_next_line.c get_next_line_utils.c get_next_line.h`

## Algorithm

### Chosen approach: a static accumulation buffer

A `static char *saved` holds every byte that has been read from the file descriptor but not yet returned to the caller. Each call does four steps:

1. **Initialise.** On the first call, `saved` becomes an empty string (`init_saved`).
2. **Fill.** While `saved` contains no `\n`, `read` another `BUFFER_SIZE` bytes into a temporary buffer, null-terminate it, and append it to `saved` with `ft_strjoin` (`get_read_add`). The loop stops when a `\n` appears or when `read` returns `0` (end of file). A negative return is an error: everything is freed and `NULL` is returned.
3. **Extract.** Copy `saved` up to and including the first `\n` (or to the end of the string if there is none) into a new string (`get_line`). That string is the return value. If it would be empty, we are at EOF and the function returns `NULL`.
4. **Trim.** Replace `saved` with the part that comes after the extracted line (`get_cut`), ready for the next call.

### Why this design

- **`read` cannot be undone.** A file descriptor can be a pipe, a terminal or a socket, so we cannot `lseek` back. A read of `BUFFER_SIZE` bytes will almost always overshoot the end of the line, and those extra bytes are gone from the descriptor. They must be stored somewhere that survives between calls, which is exactly what a `static` variable provides, and no global variable is needed.
- **Independent of `BUFFER_SIZE`.** Lines are assembled by appending chunks until a `\n` shows up, so the algorithm works whether the buffer is 1 byte (one `read` per character) or larger than the whole file. A line can span many reads, and one read can contain many lines; both cases are handled by the same loop and by keeping the remainder in `saved`.
- **Reads only what is needed.** The fill loop stops as soon as `saved` contains a newline, so the function never reads further ahead than one buffer past the line it is returning. This matters for stdin and other streams, where reading more would block.
- **Simple ownership rules, no leaks.** `saved` always points to either `NULL` or one heap string owned by the function. Each step builds a new string and frees the old one, and every error path frees the temporary buffer, `saved` and any partially built line. On EOF or error `saved` is reset to `NULL`, so the next call starts clean.
- **Fits the Norm.** Splitting the work into small single-purpose helpers keeps every function under 25 lines and the file under 5 functions.

### Alternatives considered

| Alternative | Why it was not chosen |
|---|---|
| Read one byte at a time with `read(fd, &c, 1)` | Correct and needs no leftover storage, but makes one system call per character, which is very slow. It also ignores `BUFFER_SIZE`, which the subject requires. |
| Keep the leftover as a linked list of chunks | Avoids re-copying data on append, but adds a node type, more allocations per read and more cleanup paths, which is harder to keep correct and within the Norm. |
| Grow a buffer with `realloc` and doubling | Gives amortised linear appends, but `realloc` is not an allowed function. |

### Complexity and limits

- Extracting a line and trimming `saved` are both linear in the size of the data they copy.
- `ft_strjoin` copies the whole of `saved` each time a chunk is appended. A line of length *L* read with a buffer of size *B* needs about *L / B* appends, so building it costs O(*L*² / *B*) in the worst case. For ordinary line lengths this is negligible, and it shrinks as `BUFFER_SIZE` grows. It is the main trade-off of choosing simplicity over a chunk list.
- `ft_strchr` rescans `saved` from the start on each loop iteration, which adds a constant factor on very long lines but does not change correctness.
- There is one `static` pointer, so the function tracks **one file descriptor at a time**. Interleaving calls on two different descriptors would mix their data. Handling several descriptors would need one saved string per `fd` (the bonus part of the project).

## Resources

- `man 2 read`, `man 3 malloc`, `man 3 free`
- [42 Norm / norminette](https://github.com/42School/norminette)
- [System Calls](https://web.eecs.utk.edu/~jplank/plank/classes/cs360/360/notes/Syscall-Intro/lecture.html)

### Use of AI

Claude was used for these tasks only:

- Running norminette on the finished code and fixing its errors: converting space indentation to tabs, splitting the two functions that were over 25 lines, moving `get_cut` into the utils file to respect the 5-functions-per-file limit, and adding the missing 42 header to `get_next_line_utils.c`.
- Testing the result with several `BUFFER_SIZE` values under AddressSanitizer.
- Drafting this README.

The design of the algorithm and the core code of the project were written by the author, who reviewed all of the AI's changes.
