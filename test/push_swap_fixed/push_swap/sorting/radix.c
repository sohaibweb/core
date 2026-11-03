/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:00:00 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 15:00:00 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while (((size - 1) >> bits) != 0)
		bits++;
	return (bits);
}

static void	sort_bit(t_ctx *c, int size, int bit)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((c->a->index >> bit) & 1)
			ra(c);
		else
			pb(c);
		i++;
	}
	while (c->b)
		pa(c);
}

void	radix_sort(t_ctx *c)
{
	int	size;
	int	max_bits;
	int	bit;

	size = ft_lstsize(c->a);
	if (size < 2)
		return ;
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		sort_bit(c, size, bit);
		bit++;
	}
}
