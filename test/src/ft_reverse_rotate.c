/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 15:27:25 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/17 15:27:27 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_push_swap.h"

void    ft_reverse_rotate(t_list **stack)
{
    t_list  *last;
    t_list  *back_last;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    back_last = *stack;
    while(back_last->next->next)
        back_last = back_last->next;
    last = back_last->next;
    back_last->next = NULL;
    last->next = *stack;
    *stack = last;
}

void    rra(t_list **stack_a)
{
    ft_reverse_rotate(stack_a);
    write(1, "rra\n", 4);
}
void    rrb(t_list **stack_b)
{
    ft_reverse_rotate(stack_b);
    write(1,"rrb\n", 4);
}

void    rrr(t_list **stack_a, t_list **stack_b)
{
    unsigned int    count_a;
    unsigned int    count_b;

    count_a = ft_lstsize(*stack_a);
    count_b = ft_lstsize(*stack_b);
    if (count_a > 1)
        ft_reverse_rotate(stack_a);
    if (count_b > 1)
        ft_reverse_rotate(stack_b);
    write(1,"rrr\n", 4);
}