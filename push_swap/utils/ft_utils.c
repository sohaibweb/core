/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:12:16 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/27 13:12:18 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_stack(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

t_strategy	get_strategy(int argc, char **argv, int *start, int *error)
{
	t_strategy	strategy;

	strategy = ADAPTIVE;
	*start = 1;
	*error = 0;
	while (*start < argc && argv[*start][0] == '-' && argv[*start][1] == '-')
	{
		if (ft_strcmp(argv[*start], "--simple") == 0)
			strategy = SIMPLE;
		else if (ft_strcmp(argv[*start], "--medium") == 0)
			strategy = MEDIUM;
		else if (ft_strcmp(argv[*start], "--complex") == 0)
			strategy = COMPLEX;
		else if (ft_strcmp(argv[*start], "--adaptive") == 0)
			strategy = ADAPTIVE;
		else if (ft_strcmp(argv[*start], "--bench") != 0)
		{
			*error = 1;
			return (strategy);
		}
		(*start)++;
	}
	return (strategy);
}

int	has_bench(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			return (1);
		i++;
	}
	return (0);
}
