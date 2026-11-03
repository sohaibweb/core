/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 19:04:51 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 19:04:52 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	get_rank_pos(t_list *stack, int target)
{
	int	pos;

	pos = 0;
	while (stack && stack->index != target)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

static void	push_min_to_b(t_list **stack_a, t_list **stack_b, int target)
{
	int	pos;
	int	size;

	pos = get_rank_pos(*stack_a, target);
	size = ft_lstsize(*stack_a);
	if (pos <= size / 2)
	{
		while ((*stack_a)->index != target)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->index != target)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	sort_simple(t_list **stack_a, t_list **stack_b)
{
	int	target;
	int	size;

	size = ft_lstsize(*stack_a);
	if (size < 2)
		return ;
	target = 0;
	while (size > 2)
	{
		push_min_to_b(stack_a, stack_b, target);
		target++;
		size--;
	}
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
