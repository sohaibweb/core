/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:00:00 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 15:00:00 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static t_mode	pick_mode(t_ctx *c)
{
	if (c->mistakes * 5 < c->pairs)
		return (SIMPLE);
	if (c->mistakes * 2 < c->pairs)
		return (MEDIUM);
	return (COMPLEX);
}

int	push_swap(t_ctx *c)
{
	int	size;

	size = ft_lstsize(c->a);
	c->pairs = (long long)size * (size - 1) / 2;
	c->mistakes = disorder(c->a);
	c->used = c->mode;
	if (c->mode == ADAPTIVE)
		c->used = pick_mode(c);
	if (c->mistakes == 0)
		return (0);
	if (assign_indices(c->a, size))
		return (1);
	if (c->mode == ADAPTIVE && size <= 5)
		sort_small(c);
	else if (c->used == SIMPLE)
		sort_simple(c);
	else if (c->used == MEDIUM)
		sort_big(c, size);
	else
		radix_sort(c);
	return (0);
}
