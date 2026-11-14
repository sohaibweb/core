/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 10:23:36 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/27 11:27:00 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_swap(t_list **stack)
{
	t_list	*first_node;
	t_list	*next_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	next_node = first_node->next;
	first_node->next = next_node->next;
	next_node->next = first_node;
	*stack = next_node;
}

void	sa(t_list **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	ft_swap(stack_a);
	write(1, "sa\n", 3);
	bench_add(OP_SA);
}

void	sb(t_list **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	ft_swap(stack_b);
	write(1, "sb\n", 3);
	bench_add(OP_SB);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	unsigned int	count_a;
	unsigned int	count_b;

	count_a = ft_lstsize(*stack_a);
	count_b = ft_lstsize(*stack_b);
	if (count_a < 2 && count_b < 2)
		return ;
	if (count_a > 1)
		ft_swap(stack_a);
	if (count_b > 1)
		ft_swap(stack_b);
	write(1, "ss\n", 3);
	bench_add(OP_SS);
}
