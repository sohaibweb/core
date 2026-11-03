/* ************************************************************************** */
/*                                                                            */
/*   sf_range.c                                       ███████╗███████╗        */
/*   By: sohaib <sohaib@student.com>                  ██╔════╝██╔════╝        */
/*   Created: 2026/10/06 23:09:56 by sohaib           ███████╗█████╗          */
/*   Updated: 2026/10/06 23:09:56 by sohaib           ╚════██║██╔══╝          */
/*                                                    ███████║██║             */
/*                                                    ╚══════╝╚═╝             */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int     len(int start, int end)
{
    int count;

    count = 0;
    if (start == end)
        count = 1;
    if(start < end)
    {
        while (start <= end)
        {
            count++;
            start++;
        }
    }
    else if(start > end)
    {
        while (start >= end)
        {
            count++;
            start--;
        }
    }
    return count;
}
int     *sf_range(int start, int end)
{
    int     i;
    int     len1;
    int     *result;

    i = 0;
    len1 = len(start, end);
    result = malloc(sizeof(int) * (len1));
    if (!result)
        return (0);
    if (start == end)
        result[0] = start;
    else if (start < end)
    {       
        while ( start <= end)
        {
            result[i] = start;
            start++;
            i++;
        }
    }
    else if (start > end)
    {
        while (start >= end)
        {
            result[i] = start;
            i++;
            start--;
        }
    }
    return (result);
}
int main()
{
    int *a;

    a = sf_range(1, 3);
    for (int i = 0; i < 3; i++){
    printf("%d\n", a[i]);}
}