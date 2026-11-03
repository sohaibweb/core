/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 16:32:32 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/27 11:55:35 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	disorder(t_list *stack)
{
	t_list	*node;
	t_list	*next_node;
	int		count;

	count = 0;
	node = stack;
	while (node)
	{
		next_node = node->next;
		while (next_node)
		{
			if (node->data > next_node->data)
				count++;
			next_node = next_node->next;
		}
		node = node->next;
	}
	return (count);
}

double	disorder_ratio(t_list *stack)
{
	int	size;
	int	count;
	int	total;

	size = ft_lstsize(stack);
	if (size < 2)
		return (0.0);
	count = disorder(stack);
	total = size * (size - 1) / 2;
	return ((double)count / total);
}
