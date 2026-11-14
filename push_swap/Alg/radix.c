/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 19:04:03 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 19:04:05 by sabu-msa         ###   ########.fr       */
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

static void	sort_bit(t_list **stack_a, t_list **stack_b, int size, int bit)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((*stack_a)->index >> bit) & 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		i++;
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	max_bits;
	int	bit;

	size = ft_lstsize(*stack_a);
	if (size < 2)
		return ;
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		sort_bit(stack_a, stack_b, size, bit);
		bit++;
	}
}
