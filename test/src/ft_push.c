/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 15:26:39 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/17 15:26:49 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    pa(t_list **stack_a, t_list **stack_b)
{
    t_list  *new_node;
    if (!stack_a || !stack_b || !*stack_b)
        return ;
    new_node= *stack_b;
    *stack_b = (*stack_b)->next;
    new_node->next = NULL;
    ft_lstadd_front(stack_a , new_node);
    write(1, "pa\n", 3);
}

void    pb(t_list **stack_a, t_list **stack_b)
{
    t_list  *new_node;
    if (!stack_b || !stack_a || !*stack_a)
        return ;
    new_node= *stack_a;
    *stack_a = (*stack_a)->next;
    new_node->next = NULL;
    ft_lstadd_front(stack_b , new_node);
    write(1, "pb\n", 3);
}
