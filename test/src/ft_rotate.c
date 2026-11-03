/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 11:24:37 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/18 11:24:39 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    ft_rotate(t_list **stack)
{
    t_list  *first;
    t_list  *last;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    first = *stack;
    *stack = first->next;
    first->next = NULL;
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = first;
}

void    ra(t_list **stack_a)
{
    ft_rotate(stack_a);
    write(1, "ra\n", 3);
}
void    rb(t_list **stack_b)
{
    ft_rotate(stack_b);
    write(1, "rb\n", 3);
}

void    rr(t_list **stack_a, t_list **stack_b)
{
    unsigned int    count_a;
    unsigned int    count_b;

    count_a = ft_lstsize(*stack_a);
    count_b = ft_lstsize(*stack_b);
    if (count_a > 1)
        ft_rotate(stack_a);
    if (count_b > 1)
        ft_rotate(stack_b);
    write(1, "rr\n", 3);
}
