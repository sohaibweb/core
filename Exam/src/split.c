#include <stdlib.h>

int sper(char c)
{
    if (c == ' ' || c == '\n' || c == '\t')
        return 1;
    return 0;
}

int lin_word(char *arr)
{
    int i;

    i = 0;
    while (arr[i] && !sper(arr[i]))
        i++;
    return i;
}

int     count_word(char *str)
{
    int i;
    int j;
    int count;
    int ind_word;

    i = 0;
    count = 0;
    ind_word = 0;
    while(str[i])
    {
        if (ind_word == 0 && !sper(str[i]))
        {
            count++;
            ind_word = 1;
        }
        else
            ind_word = 0;
        i++;
    }
    return (count);
}

char    *ft_dubstr(char *str)
{
    int     i;
    int     len;
    char    *result;

    i = 0;
    len = lin_word(str);
    result = malloc(sizeof(char) * (len + 1));
    if (!result)
        return NULL;
    while(i < len)
    {
        result[i] = str[i];
        i++;
    }
    result[i] = '\0';
    return (result);
}
char    **ft_split(char *str)
{
    int     i;
    int     j;
    int     len;
    int     len_word;
    char    **result;

    i = 0;
    j = 0;
    len_word = count_word(str);
    result = malloc(sizeof(char *) * (len_word + 1));
    if (!result)
        return (NULL);
    while (i < len_word)
    {
        while (str[j] && sper(str[j]))
            j++;
        len = lin_word(str + j);
        result[i] = ft_dubstr(str + j);
        i++;
        j += len;
    }
    result[i] = NULL;
    return (result);
}

#include <stdio.h>

int main()
{
    int     i;
    char    arr[] = "sohaib abu musameh";
    char    **r;

    r = ft_split(arr);
    i = 0;
    while (r[i])
    {
        printf("%s\n", r[i]);
        i++;
    }
}