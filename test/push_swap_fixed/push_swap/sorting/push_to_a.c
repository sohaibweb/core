/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:00:00 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 15:00:00 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	find_pos(t_list *stack, int target)
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

static int	cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (size - pos);
}

static void	bring_to_top(t_ctx *c, int target, int size)
{
	int	pos;

	pos = find_pos(c->b, target);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(c);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(c);
	}
}

static int	second_is_closer(t_ctx *c, int size)
{
	int	first;
	int	second;

	if (size < 2)
		return (0);
	first = cost(find_pos(c->b, size - 1), size);
	second = cost(find_pos(c->b, size - 2), size);
	return (second < first);
}

void	push_to_a(t_ctx *c, int size)
{
	while (size > 0)
	{
		if (second_is_closer(c, size))
		{
			bring_to_top(c, size - 2, size);
			pa(c);
			bring_to_top(c, size - 1, size - 1);
			pa(c);
			sa(c);
			size -= 2;
		}
		else
		{
			bring_to_top(c, size - 1, size);
			pa(c);
			size--;
		}
	}
}
