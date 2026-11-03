/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 11:24:54 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/18 11:24:59 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

int    chack_duplicate(int argc, char **argv)
{
    int    i;
    int    j;

    i = 1;
    while (i < argc - 1)
    {
        j = i + 1;
        while (j < argc)
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int     check_input(char *arr)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(arr);
    if (!arr[i])
        return (1);
    if (arr[0] == '-' || arr[0] == '+')
    {
        if (arr[1] == '\0')
            return (1);
        i++;
    }
    while(i < len)
    {
        if (arr[i] && arr[i] >= '0' && arr[i] <= '9')
            i++;
        else
            return (1);
    }
    return (0);
}

int     check_overflow(char *arr)
{
    char    *check;
    int     len;
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (arr[0] == '-' || arr[0] == '+')
        i++;
    while (arr[i] == '0')
        i++;
    len = ft_strlen(arr + i);
    if (arr[0] == '-')
        check = "2147483648";
    else
        check = "2147483647";
    if (len > 10)
        return (1);
    if (len < 10)
        return (0);
    while(arr[i])
    {
        if (arr[i] < check[j])
            return (0);
        if (arr[i] > check[j])
            return (1);
        i++;
        j++;
    }
    return (0);
}

int     main(int argc, char **argv)
{
    int     i;
    int     n;
    t_list  *stack;

    i = 1;
    stack = NULL;
    if (argc > 1)
    {
        while(i < argc)
        {
            if ((check_input(argv[i])) || (check_overflow(argv[i])))
                return (write_error());
            i++;
        }
        if (chack_duplicate(argc, argv))
            return (write_error());
        i = 1;
        while (argv[i])
        {
            n = ft_atoi(argv[i]);
            ft_lstadd_back(&stack, ft_lstnew(&n));
            i++;
        }
        while (stack)
	    {
		    printf("%d\n", *stack->data);
		    stack = stack->next;
	    }
    }
    return (0);
}
