/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:00:00 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 15:00:00 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	sort_three(t_ctx *c)
{
	int	x;
	int	y;
	int	z;

	x = c->a->data;
	y = c->a->next->data;
	z = c->a->next->next->data;
	if (x > y && y < z && x < z)
		sa(c);
	else if (x > y && y > z)
	{
		sa(c);
		rra(c);
	}
	else if (x > y && y < z && x > z)
		ra(c);
	else if (x < y && y > z && x < z)
	{
		sa(c);
		ra(c);
	}
	else if (x < y && y > z && x > z)
		rra(c);
}

static int	get_min_index(t_list *stack)
{
	int	min;
	int	index;
	int	min_index;

	min = stack->data;
	index = 0;
	min_index = 0;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			min_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (min_index);
}

static void	sort_five(t_ctx *c)
{
	int	size;
	int	min_index;

	size = ft_lstsize(c->a);
	while (size > 3)
	{
		min_index = get_min_index(c->a);
		if (min_index <= size / 2)
		{
			while (min_index-- > 0)
				ra(c);
		}
		else
		{
			while (min_index++ < size)
				rra(c);
		}
		pb(c);
		size--;
	}
	sort_three(c);
	pa(c);
	pa(c);
}

void	sort_small(t_ctx *c)
{
	int	size;

	if (!c->a || !c->a->next)
		return ;
	size = ft_lstsize(c->a);
	if (size == 2)
	{
		if (c->a->data > c->a->next->data)
			sa(c);
		return ;
	}
	if (size == 3)
		sort_three(c);
	else
		sort_five(c);
}
