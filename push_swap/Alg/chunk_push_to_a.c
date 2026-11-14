/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 19:04:35 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 19:04:38 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	max_position(t_list *stack)
{
	int	pos;
	int	max_pos;
	int	max;

	pos = 0;
	max_pos = 0;
	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			max_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (max_pos);
}

static void	bring_max_to_top(t_list **stack_b, int size)
{
	int	pos;

	pos = max_position(*stack_b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(stack_b);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(stack_b);
	}
}

void	push_to_a(t_list **stack_a, t_list **stack_b, int size)
{
	while (size > 0)
	{
		bring_max_to_top(stack_b, size);
		pa(stack_a, stack_b);
		size--;
	}
}
