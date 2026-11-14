/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-lata <yal-lata@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:39:14 by yal-lata          #+#    #+#             */
/*   Updated: 2026/11/03 15:39:17 by yal-lata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	*bench_counts(void)
{
	static int	counts[OP_COUNT];

	return (counts);
}

void	bench_add(int op)
{
	int	*counts;

	counts = bench_counts();
	counts[op]++;
}

static int	total_ops(void)
{
	int	*c;
	int	i;
	int	sum;

	c = bench_counts();
	sum = 0;
	i = 0;
	while (i < OP_COUNT)
	{
		sum += c[i];
		i++;
	}
	return (sum);
}

static void	put_pair(char *name, int op, char *end)
{
	ft_putstr(name);
	ft_putstr(": ");
	ft_putint(bench_counts()[op]);
	ft_putstr(end);
}

void	bench_print(double ratio, t_strategy strategy, t_list **stack)
{
	ft_putstr("[bench] disorder: ");
	put_disorder(ratio);
	ft_putstr("\n");
	put_strategy(strategy, stack, ratio);
	ft_putstr("[bench] total_ops: ");
	ft_putint(total_ops());
	ft_putstr("\n");
	ft_putstr("[bench] ");
	put_pair("sa", OP_SA, " ");
	put_pair("sb", OP_SB, " ");
	put_pair("ss", OP_SS, " ");
	put_pair("pa", OP_PA, " ");
	put_pair("pb", OP_PB, "\n");
	ft_putstr("[bench] ");
	put_pair("ra", OP_RA, " ");
	put_pair("rb", OP_RB, " ");
	put_pair("rr", OP_RR, " ");
	put_pair("rra", OP_RRA, " ");
	put_pair("rrb", OP_RRB, " ");
	put_pair("rrr", OP_RRR, "\n");
}
