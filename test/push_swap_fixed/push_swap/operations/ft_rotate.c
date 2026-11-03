/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:00:00 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 15:00:00 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra(t_ctx *c)
{
	if (!has_two(c->a))
		return ;
	ft_rotate(&c->a);
	c->ops[OP_RA]++;
	write(1, "ra\n", 3);
}

void	rb(t_ctx *c)
{
	if (!has_two(c->b))
		return ;
	ft_rotate(&c->b);
	c->ops[OP_RB]++;
	write(1, "rb\n", 3);
}

void	rr(t_ctx *c)
{
	if (!has_two(c->a) && !has_two(c->b))
		return ;
	if (has_two(c->a))
		ft_rotate(&c->a);
	if (has_two(c->b))
		ft_rotate(&c->b);
	c->ops[OP_RR]++;
	write(1, "rr\n", 3);
}
