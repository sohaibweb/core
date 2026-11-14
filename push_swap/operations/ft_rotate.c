/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 11:24:37 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/27 11:24:07 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

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

void	ra(t_list **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
	bench_add(OP_RA);
}

void	rb(t_list **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
	bench_add(OP_RB);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	unsigned int	count_a;
	unsigned int	count_b;

	count_a = ft_lstsize(*stack_a);
	count_b = ft_lstsize(*stack_b);
	if (count_a < 2 && count_b < 2)
		return ;
	if (count_a > 1)
		ft_rotate(stack_a);
	if (count_b > 1)
		ft_rotate(stack_b);
	write(1, "rr\n", 3);
	bench_add(OP_RR);
}
