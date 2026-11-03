/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:00:00 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 15:00:00 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static int	chunk_size(int size)
{
	int	chunk;

	chunk = ft_sqrt(size) * 5 / 4;
	if (chunk < 1)
		chunk = 1;
	return (chunk);
}

static void	push_one(t_ctx *c, int *start, int *end)
{
	int	small;

	pb(c);
	small = (c->b->index <= (*start + *end) / 2);
	(*start)++;
	(*end)++;
	if (small && c->a && c->a->index > *end)
		rr(c);
	else if (small)
		rb(c);
}

void	push_to_b(t_ctx *c, int size)
{
	int	start;
	int	end;

	start = 0;
	end = chunk_size(size) - 1;
	while (c->a)
	{
		if (c->a->index <= end)
			push_one(c, &start, &end);
		else
			ra(c);
	}
}

void	sort_big(t_ctx *c, int size)
{
	push_to_b(c, size);
	push_to_a(c, size);
}
