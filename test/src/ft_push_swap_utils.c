/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 11:19:51 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/17 11:19:53 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_push_swap.h"

int    write_error(void)
{
        write(2, "Error\n", 6);
        return (1);
}

int     ft_strlen(char *arr)
{
        int     i;

        i = 0;
        while(arr[i])
                i++;
        return(i);
}

unsigned int    ft_lstsize(t_list *lst)
{
        unsigned int    count;

        count = 0;
        while (lst != NULL)
        {
                count++;
                lst = lst->next;
        }
        return (count);
}

t_list  *ft_lstnew(int *data)
{
        t_list  *node;

        node = malloc(sizeof(t_list));
        if (!node)
        {
                return (NULL);
        }
        node->data = malloc(sizeof(int));
        if (!node->data)
        {
                free(node);
                return (NULL);
        }
        *node->data = *data;
        node->next = NULL;
        return (node);
}

t_list  *ft_lstlast(t_list *lst)
{
        if (!lst)
                return (NULL);
        while (lst->next)
        {
                lst = lst->next;
        }
        return (lst);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
        t_list  *last;

        last = ft_lstlast(*lst);
        if (!last)
                *lst = new;
        else
                last->next = new;
}

void    ft_lstadd_front(t_list **lst, t_list *new)

{
        new->next = *lst;
        *lst = new;
}

static void     ft_skip_and_sign(const char *nptr, size_t *i, int *x)
{
        unsigned char   *str;

        str = (unsigned char *)nptr;
        while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
        {
                (*i)++;
        }
        if (str[*i] == '-' || str[*i] == '+')
        {
                if (str[*i] == '-')
                {
                        *x *= -1;
                }
                (*i)++;
        }
}

int     ft_atoi(const char *nptr)
{
        size_t  i;
        int             x;
        long    r;

        i = 0;
        x = 1;
        r = 0;
        ft_skip_and_sign(nptr, &i, &x);
        while (nptr[i] >= '0' && nptr[i] <= '9')
        {
                r = r * 10 +(nptr[i] - '0');
                i++;
        }
        return (r * x);
}
