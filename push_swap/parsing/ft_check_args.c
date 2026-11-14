/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:24:01 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/27 11:50:00 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	check_duplicate(t_list *stack)
{
	t_list	*current;
	t_list	*check;

	current = stack;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->data == check->data)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

int	check_input(char *arr)
{
	int	i;
	int	len;

	i = 0;
	if (!arr)
		return (1);
	len = ft_strlen(arr);
	if (!arr[i])
		return (1);
	if (arr[0] == '-' || arr[0] == '+')
	{
		if (arr[1] == '\0')
			return (1);
		i++;
	}
	while (i < len)
	{
		if (arr[i] && arr[i] >= '0' && arr[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

static int	check_arr(char *arr, char *check)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		if (arr[i] < check[j])
			return (0);
		if (arr[i] > check[j])
			return (1);
		i++;
		j++;
	}
	return (0);
}

int	check_overflow(char *arr)
{
	char	*check;
	int		len;
	int		i;

	i = 0;
	if (arr[0] == '-' || arr[0] == '+')
		i++;
	while (arr[i] == '0')
		i++;
	len = ft_strlen(arr + i);
	if (arr[0] == '-')
		check = "2147483648";
	else
		check = "2147483647";
	if (len > 10)
		return (1);
	if (len < 10)
		return (0);
	if (!check_arr(arr + i, check))
		return (0);
	else
		return (1);
	return (0);
}
