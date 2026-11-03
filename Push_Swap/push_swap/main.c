/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 11:24:54 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/27 12:56:40 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	process_word(char *word, t_list **stack)
{
	int		n;
	t_list	*new_node;

	if (check_input(word) || check_overflow(word))
		return (1);
	n = ft_atoi(word);
	new_node = ft_lstnew(&n);
	if (!new_node)
		return (1);
	ft_lstadd_back(stack, new_node);
	return (0);
}

static int	process_args(char *arg, t_list **stack)
{
	int		j;
	char	**result;

	result = ft_split(arg, ' ');
	if (!result)
		return (1);
	if (!result[0])
	{
		free_split(result);
		return (1);
	}
	j = 0;
	while (result[j])
	{
		if (process_word(result[j], stack))
		{
			free_split(result);
			return (1);
		}
		j++;
	}
	free_split(result);
	return (0);
}

static int	check_args(int argc, char **argv, t_list **stack,
	t_strategy *strategy)
{
	int		i;
	int		start;
	int		error;

	*strategy = get_strategy(argc, argv, &start, &error);
	if (error)
		return (1);
	if (start >= argc)
		return (1);
	i = start;
	while (i < argc)
	{
		if (process_args(argv[i], stack))
			return (1);
		i++;
	}
	return (0);
}

static int	sort_stack(t_list **stack, t_strategy strategy)
{
	if (disorder(*stack) == 0)
		return (0);
	if (ft_lstsize(*stack) > 1)
		push_swap(stack, strategy);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list		*stack;
	t_strategy	strategy;

	stack = NULL;
	if (argc < 2)
		return (0);
	if (check_args(argc, argv, &stack, &strategy))
		return (free_stack(stack), write_error());
	if (check_duplicate(stack))
		return (free_stack(stack), write_error());
	if (sort_stack(&stack, strategy))
		return (free_stack(stack), write_error());
	free_stack(stack);
	return (0);
}
