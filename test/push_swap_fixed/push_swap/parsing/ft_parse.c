/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:00:00 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 15:00:00 by sabu-msa         ###   ########.fr       */
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

static int	is_flag(char *arg, t_ctx *c)
{
	if (!ft_strcmp(arg, "--bench"))
		c->bench = 1;
	else if (!ft_strcmp(arg, "--simple"))
		c->mode = SIMPLE;
	else if (!ft_strcmp(arg, "--medium"))
		c->mode = MEDIUM;
	else if (!ft_strcmp(arg, "--complex"))
		c->mode = COMPLEX;
	else if (!ft_strcmp(arg, "--adaptive"))
		c->mode = ADAPTIVE;
	else
		return (0);
	return (1);
}

int	parse_args(int argc, char **argv, t_ctx *c)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_flag(argv[i], c) && process_args(argv[i], &c->a))
			return (1);
		i++;
	}
	return (0);
}
