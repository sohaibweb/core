/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:00:00 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 15:00:00 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	pa(t_ctx *c)
{
	t_list	*node;

	if (!c->b)
		return ;
	node = c->b;
	c->b = c->b->next;
	ft_lstadd_front(&c->a, node);
	c->ops[OP_PA]++;
	write(1, "pa\n", 3);
}

void	pb(t_ctx *c)
{
	t_list	*node;

	if (!c->a)
		return ;
	node = c->a;
	c->a = c->a->next;
	ft_lstadd_front(&c->b, node);
	c->ops[OP_PB]++;
	write(1, "pb\n", 3);
}
