#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

    /* ft_isalpha */
int main()
{
    printf("%d\n", ft_isalpha('a'));
    printf("%d\n", ft_isalpha('Z'));
    printf("%d\n", ft_isalpha('5'));
    printf("%d\n", ft_isalpha(' '));
    printf("%d\n", ft_isalpha(-1));

    return 0;
}

    /* ft_isdigit */
int main()
{
    printf("%d\n", ft_isdigit('0'));
    printf("%d\n", ft_isdigit('9'));
    printf("%d\n", ft_isdigit('a'));
    printf("%d\n", ft_isdigit(' '));
    printf("%d\n", ft_isdigit(-5));

    return 0;
}

    /* ft_isalnum */
int main()
{
    printf("%d\n", ft_isalnum('a'));
    printf("%d\n", ft_isalnum('5'));
    printf("%d\n", ft_isalnum('!'));
    printf("%d\n", ft_isalnum(' '));
    printf("%d\n", ft_isalnum(-1));

    return 0;
}

    /* ft_isascii */
int main()
{
    printf("%d\n", ft_isascii('a'));
    printf("%d\n", ft_isascii(0));
    printf("%d\n", ft_isascii(127));
    printf("%d\n", ft_isascii(128));
    printf("%d\n", ft_isascii(-1));

    return 0;
}

    /* ft_isprint */
int main()
{
    printf("%d\n", ft_isprint('a'));
    printf("%d\n", ft_isprint(' '));
    printf("%d\n", ft_isprint('\n'));
    printf("%d\n", ft_isprint(31));
    printf("%d\n", ft_isprint(127));

    return 0;
}

    /* ft_strlen */
int main()
{
    printf("%zu\n", ft_strlen("hello"));
    printf("%zu\n", ft_strlen(""));
    printf("%zu\n", ft_strlen("a"));
    printf("%zu\n", ft_strlen("hello world 123"));

    return 0;
}

    /* ft_memset */
int main()
{
    char buf[20] = "abcdefghij";

    ft_memset(buf, 'x', 5);
    printf("%s\n", buf);

    ft_memset(buf, 0, 20);
    printf("%s\n", buf);

    return 0;
}

    /* ft_bzero */
int main()
{
    char buf[20] = "abcdefghij";

    ft_bzero(buf, 5);
    printf("%s\n", buf);

    return 0;
}

    /* ft_memcpy */
int main()
{
    char src[] = "Hello World";
    char dst[20];

    ft_memcpy(dst, src, 12);
    printf("%s\n", dst);

    return 0;
}

    /* ft_memmove */
int main()
{
    char buf[30] = "Hello World Overlap";

    ft_memmove(buf + 6, buf, 5);
    printf("%s\n", buf);

    return 0;
}

    /* ft_strlcpy */
int main()
{
    char dst[20];
    size_t r;

    r = ft_strlcpy(dst, "Hello", sizeof(dst));
    printf("%s\n", dst);
    printf("%zu\n", r);

    r = ft_strlcpy(dst, "Hello World", 5);
    printf("%s\n", dst);
    printf("%zu\n", r);

    return 0;
}

    /* ft_strlcat */
int main()
{
    char dst[20] = "Hello ";
    size_t r;

    r = ft_strlcat(dst, "World", sizeof(dst));
    printf("%s\n", dst);
    printf("%zu\n", r);

    return 0;
}

    /* ft_toupper */
int main()
{
    printf("%d\n", ft_toupper('a'));
    printf("%d\n", ft_toupper('Z'));
    printf("%d\n", ft_toupper('5'));

    return 0;
}

    /* ft_tolower */
int main()
{
    printf("%d\n", ft_tolower('A'));
    printf("%d\n", ft_tolower('z'));
    printf("%d\n", ft_tolower('5'));

    return 0;
}

    /* ft_strchr */
int main()
{
    char *s = "Hello, World!";

    printf("%s\n", ft_strchr(s, 'W'));
    printf("%s\n", ft_strchr(s, '\0'));

    return 0;
}

    /* ft_strrchr */
int main()
{
    char *s = "Hello, World!";

    printf("%s\n", ft_strrchr(s, 'o'));
    printf("%s\n", ft_strrchr(s, '\0'));

    return 0;
}

    /* ft_strncmp */
int main()
{
    printf("%d\n", ft_strncmp("Hello", "Hello", 5));
    printf("%d\n", ft_strncmp("Hello", "Help", 3));
    printf("%d\n", ft_strncmp("Hello", "Help", 4));
    printf("%d\n", ft_strncmp("abc", "abd", 0));

    return 0;
}

    /* ft_memchr */
int main()
{
    char *s = "Hello, World!";

    printf("%s\n", (char *)ft_memchr(s, 'W', 13));

    return 0;
}

    /* ft_memcmp */
int main()
{
    printf("%d\n", ft_memcmp("abc", "abc", 3));
    printf("%d\n", ft_memcmp("abc", "abd", 3));
    printf("%d\n", ft_memcmp("abc", "abd", 0));

    return 0;
}

    /* ft_strnstr */
int main()
{
    char *s = "Hello, World!";

    printf("%s\n", ft_strnstr(s, "World", 13));
    printf("%s\n", ft_strnstr(s, "xyz", 13));
    printf("%s\n", ft_strnstr(s, "World", 5));

    return 0;
}

    /* ft_atoi */
int main()
{
    printf("%d\n", ft_atoi("42"));
    printf("%d\n", ft_atoi("   -42"));
    printf("%d\n", ft_atoi("+42"));
    printf("%d\n", ft_atoi("42abc"));
    printf("%d\n", ft_atoi("abc"));
    printf("%d\n", ft_atoi(""));

    return 0;
}

    /* ft_calloc */
int main()
{
    int *arr;
    int i;

    arr = ft_calloc(5, sizeof(int));
    i = 0;
    while (i < 5)
    {
        printf("%d\n", arr[i]);
        i++;
    }
    free(arr);

    return 0;
}

    /* ft_strdup */
int main()
{
    char *s;

    s = ft_strdup("Hello, World!");
    printf("%s\n", s);
    free(s);

    s = ft_strdup("");
    printf("%s\n", s);
    free(s);

    return 0;
}
