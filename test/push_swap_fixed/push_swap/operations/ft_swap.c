/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:00:00 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 15:00:00 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_swap(t_list **stack)
{
	t_list	*first_node;
	t_list	*next_node;

	first_node = *stack;
	next_node = first_node->next;
	first_node->next = next_node->next;
	next_node->next = first_node;
	*stack = next_node;
}

void	sa(t_ctx *c)
{
	if (!has_two(c->a))
		return ;
	ft_swap(&c->a);
	c->ops[OP_SA]++;
	write(1, "sa\n", 3);
}

void	sb(t_ctx *c)
{
	if (!has_two(c->b))
		return ;
	ft_swap(&c->b);
	c->ops[OP_SB]++;
	write(1, "sb\n", 3);
}

void	ss(t_ctx *c)
{
	if (!has_two(c->a) && !has_two(c->b))
		return ;
	if (has_two(c->a))
		ft_swap(&c->a);
	if (has_two(c->b))
		ft_swap(&c->b);
	c->ops[OP_SS]++;
	write(1, "ss\n", 3);
}
