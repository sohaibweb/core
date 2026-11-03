/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 12:00:56 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/27 12:02:53 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	adaptive(t_list **stack_a, int size)
{
	t_list	*stack_b;
	double	ratio;

	stack_b = NULL;
	if (size <= 5)
	{
		sort_small(stack_a);
		return ;
	}
	ratio = disorder_ratio(*stack_a);
	if (!assign_indices(*stack_a, size))
		return ;
	if (ratio < 0.2)
		sort_simple(stack_a, &stack_b);
	else if (ratio < 0.5)
		sort_big(stack_a, &stack_b, size);
	else
		radix_sort(stack_a, &stack_b);
}

void	push_swap(t_list **stack_a, t_strategy strategy)
{
	t_list	*stack_b;
	int		size;

	stack_b = NULL;
	size = ft_lstsize(*stack_a);
	if (size <= 1)
		return ;
	if (!assign_indices(*stack_a, size))
		return ;
	if (strategy == SIMPLE)
		sort_simple(stack_a, &stack_b);
	else if (strategy == MEDIUM)
		sort_big(stack_a, &stack_b, size);
	else if (strategy == COMPLEX)
		radix_sort(stack_a, &stack_b);
	else
		adaptive(stack_a, size);
}
