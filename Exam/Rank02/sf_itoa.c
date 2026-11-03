/* ************************************************************************** */
/*                                                                            */
/*   sf_itoa.c                                        ███████╗███████╗        */
/*   By: sohaib <sohaib@student.com>                  ██╔════╝██╔════╝        */
/*   Created: 2026/10/06 14:19:33 by sohaib           ███████╗█████╗          */
/*   Updated: 2026/10/06 14:19:33 by sohaib           ╚════██║██╔══╝          */
/*                                                    ███████║██║             */
/*                                                    ╚══════╝╚═╝             */
/* ************************************************************************** */
#include <stdlib.h>

char    *nbr_zero()
{
    char *result;

    result = malloc(2);
    if (!result)
        return (NULL);
    result[0] = '0';
    result[1] = '\0';
    return (result);
}
char    *sf_itoa(int nbr)
{
    int i;
    int j;
    long n;
    int x;
    char *result;

    i = 0;
    j = 0;
    x = 1;
    n = nbr;
    if (n == 0)
        return(nbr_zero());
    while(nbr != 0)
    {
        nbr = nbr / 10;
        i++;
    }
    j = i;
    if (n < 0)
    {
        x = -1;
        n = n * -1;
        j++;
    }
    result = malloc(j + 1);
    if (!result)
        return(NULL);
    i = 0;
    j--;
    while(j >= 0)
    {
        result[j] = (n % 10) + '0';
        n = n / 10;
        i++;
        j--;
    }
    if (x  == -1)
        result[0] = '-';
    result[i] = '\0';
    return (result);
}