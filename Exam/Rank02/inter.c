/* Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$ */

#include <unistd.h>

int     main(int argc, char **argv)
{
    int     i;
    int     j;
    int     n;
    int     dup;

    i = 0;
    if (argc > 2)
    {
        while (argv[1][i])
        {
            n = 0;
            dup = 0;
            while (n < i)
            {
                if (argv[1][n] == argv[1][i])
                    dup +=1;
                n++;
            }
            j = 0;
            while (argv[2][j])
            {
                if (argv[1][i] == argv[2][j])
                    break;
                  j++;
            }
            if (argv[2][j] && !dup)
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}
