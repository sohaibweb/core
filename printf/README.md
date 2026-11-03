*This activity has been created as part of the 42 curriculum by
sabu-msa.*

# Description

`ft_printf` is a recreation of the standard `printf()` function in C.

The project uses variadic functions to handle the required conversions:

-   `%c` character
-   `%s` string
-   `%p` pointer in hexadecimal
-   `%d` decimal number
-   `%i` integer in base 10
-   `%u` unsigned decimal number
-   `%x` hexadecimal lowercase
-   `%X` hexadecimal uppercase
-   `%%` percent sign

# Instructions

Build the library:

``` bash
make
```

This creates:

``` text
ft_printf.a
```

Clean object files:

``` bash
make clean
```

Remove object files and the library:

``` bash
make fclean
```

Rebuild everything:

``` bash
make re
```

Use the function by including:

``` c
#include "ft_printf.h"
```

Prototype:

``` c
int ft_printf(const char *, ...);
```

# Algorithm and Data Structure

The project uses a variadic argument list with `va_start`, `va_arg`, and
`va_end`.

`ft_printf()` scans the format string character by character. When it
finds `%`, `ft_handle_format()` checks the following character and calls
the corresponding function.

Number printing uses recursion. Decimal numbers are divided by 10, and
hexadecimal numbers are divided by 16. The remainder is used to select
the character to print from the corresponding base string.

No complex data structure is used. The implementation mainly uses the
format string, local variables, and the `va_list` used for variadic
arguments.

# Resources

-   `printf()` and variadic functions from the C standard library
    documentation.
-   The 42 ft_printf subject.

AI was used to help understand C concepts, variadic arguments, and to
review implementation details. The code and project structure were
written and tested as part of the activity.
