/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:00:00 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 15:00:00 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*back_last;

	back_last = *stack;
	while (back_last->next->next)
		back_last = back_last->next;
	last = back_last->next;
	back_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_ctx *c)
{
	if (!has_two(c->a))
		return ;
	ft_reverse_rotate(&c->a);
	c->ops[OP_RRA]++;
	write(1, "rra\n", 4);
}

void	rrb(t_ctx *c)
{
	if (!has_two(c->b))
		return ;
	ft_reverse_rotate(&c->b);
	c->ops[OP_RRB]++;
	write(1, "rrb\n", 4);
}

void	rrr(t_ctx *c)
{
	if (!has_two(c->a) && !has_two(c->b))
		return ;
	if (has_two(c->a))
		ft_reverse_rotate(&c->a);
	if (has_two(c->b))
		ft_reverse_rotate(&c->b);
	c->ops[OP_RRR]++;
	write(1, "rrr\n", 4);
}
