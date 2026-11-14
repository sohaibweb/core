/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 20:53:57 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/27 12:00:27 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	sort_three(t_list **stack_a)
{
	int	x;
	int	y;
	int	z;

	x = (*stack_a)->data;
	y = (*stack_a)->next->data;
	z = (*stack_a)->next->next->data;
	if (x > y && y < z && x < z)
		sa(stack_a);
	else if (x > y && y > z)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (x > y && y < z && x > z)
		ra(stack_a);
	else if (x < y && y > z && x < z)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (x < y && y > z && x > z)
		rra(stack_a);
}

static int	get_min_index(t_list *stack)
{
	t_list	*node;
	int		min;
	int		index;
	int		min_index;

	if (!stack)
		return (-1);
	node = stack;
	min = node->data;
	index = 0;
	min_index = 0;
	while (node)
	{
		if (node->data < min)
		{
			min = node->data;
			min_index = index;
		}
		node = node->next;
		index++;
	}
	return (min_index);
}

static void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	min_index;

	size = ft_lstsize(*stack_a);
	while (size > 3)
	{
		min_index = get_min_index(*stack_a);
		if (min_index <= size / 2)
		{
			while (min_index-- > 0)
				ra(stack_a);
		}
		else
		{
			while (min_index++ < size)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		size--;
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_small(t_list **stack_a)
{
	t_list	*stack_b;
	int		size;

	stack_b = NULL;
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	size = ft_lstsize(*stack_a);
	if (!(*stack_a)->next->next)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a);
		return ;
	}
	if (size == 3)
		sort_three(stack_a);
	else
		sort_five(stack_a, &stack_b);
}
