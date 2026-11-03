/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:00:00 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 15:00:00 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	init_ctx(t_ctx *c)
{
	int	i;

	c->a = NULL;
	c->b = NULL;
	c->mode = ADAPTIVE;
	c->used = ADAPTIVE;
	c->bench = 0;
	c->mistakes = 0;
	c->pairs = 0;
	i = 0;
	while (i < OP_COUNT)
		c->ops[i++] = 0;
}

int	total_ops(t_ctx *c)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < OP_COUNT)
		total += c->ops[i++];
	return (total);
}
