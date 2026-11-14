/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 19:04:17 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 19:04:19 by sabu-msa         ###   ########.fr       */
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

	chunk = ft_sqrt(size);
	if (chunk < 1)
		chunk = 1;
	return (chunk);
}

void	push_to_b(t_list **stack_a, t_list **stack_b, int size)
{
	int	start;
	int	end;

	start = 0;
	end = chunk_size(size) - 1;
	while (*stack_a)
	{
		if ((*stack_a)->index <= end)
		{
			pb(stack_a, stack_b);
			if ((*stack_b)->index <= (start + end) / 2)
				rb(stack_b);
			start++;
			end++;
		}
		else
			ra(stack_a);
	}
}

void	sort_big(t_list **stack_a, t_list **stack_b, int size)
{
	push_to_b(stack_a, stack_b, size);
	push_to_a(stack_a, stack_b, size);
}
