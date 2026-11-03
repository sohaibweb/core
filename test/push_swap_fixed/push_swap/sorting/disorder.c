/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:00:00 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 15:00:00 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

long long	disorder(t_list *stack)
{
	t_list		*node;
	t_list		*next_node;
	long long	count;

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
