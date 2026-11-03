/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:00:00 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 15:00:00 by sabu-msa         ###   ########.fr       */
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

static void	push_min_to_b(t_ctx *c, int target)
{
	int	pos;
	int	size;

	pos = get_rank_pos(c->a, target);
	size = ft_lstsize(c->a);
	if (pos <= size / 2)
	{
		while (c->a->index != target)
			ra(c);
	}
	else
	{
		while (c->a->index != target)
			rra(c);
	}
	pb(c);
}

void	sort_simple(t_ctx *c)
{
	int	target;

	if (ft_lstsize(c->a) < 2)
		return ;
	target = 0;
	while (ft_lstsize(c->a) > 2)
	{
		push_min_to_b(c, target);
		target++;
	}
	if (c->a->index > c->a->next->index)
		sa(c);
	while (c->b)
		pa(c);
}
