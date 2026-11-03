/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indicing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:00:00 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 15:00:00 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	fill_values(t_list *stack, int *arr)
{
	int	i;

	i = 0;
	while (stack)
	{
		arr[i++] = stack->data;
		stack = stack->next;
	}
}

static void	set_ranks(t_list *stack, int *arr, int size)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (i < size)
		{
			if (stack->data == arr[i])
			{
				stack->index = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}

int	assign_indices(t_list *stack, int size)
{
	int	*arr;

	if (!stack || size <= 0)
		return (0);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (1);
	fill_values(stack, arr);
	sort_array(arr, size);
	set_ranks(stack, arr, size);
	free(arr);
	return (0);
}
