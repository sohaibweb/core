/* ************************************************************************** */
/*                                                                            */
/*   sf_atoi.c                                        ███████╗███████╗        */
/*   By: sohaib <sohaib@student.com>                  ██╔════╝██╔════╝        */
/*   Created: 2026/10/06 14:19:08 by sohaib           ███████╗█████╗          */
/*   Updated: 2026/10/06 14:19:08 by sohaib           ╚════██║██╔══╝          */
/*                                                    ███████║██║             */
/*                                                    ╚══════╝╚═╝             */
/* ************************************************************************** */
#include <stdio.h>

int    sf_atoi(const char *str)
{
    int    i;
    int    x;
    int    result;

    i = 0;
    x = 1;
    result = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            x = -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result *10 + (str[i] - '0');
        i++;
    }
    return (result * x);
}
int     main()
{
    char s[] = "-123aaa";
    printf("%d\n", sf_atoi(s));
}