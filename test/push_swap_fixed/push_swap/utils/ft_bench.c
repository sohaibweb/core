/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:00:00 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 15:00:00 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static char	*mode_name(t_mode mode)
{
	if (mode == SIMPLE)
		return ("Simple");
	if (mode == MEDIUM)
		return ("Medium");
	if (mode == COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

static char	*mode_cplx(t_mode mode)
{
	if (mode == SIMPLE)
		return ("O(n\xc2\xb2)");
	if (mode == MEDIUM)
		return ("O(n\xe2\x88\x9an)");
	return ("O(n log n)");
}

static void	put_op(char *name, int n)
{
	ft_putstr_fd(" ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(n, 2);
}

static void	put_counts(t_ctx *c)
{
	ft_putstr_fd("[bench]", 2);
	put_op("sa", c->ops[OP_SA]);
	put_op("sb", c->ops[OP_SB]);
	put_op("ss", c->ops[OP_SS]);
	put_op("pa", c->ops[OP_PA]);
	put_op("pb", c->ops[OP_PB]);
	ft_putstr_fd("\n[bench]", 2);
	put_op("ra", c->ops[OP_RA]);
	put_op("rb", c->ops[OP_RB]);
	put_op("rr", c->ops[OP_RR]);
	put_op("rra", c->ops[OP_RRA]);
	put_op("rrb", c->ops[OP_RRB]);
	put_op("rrr", c->ops[OP_RRR]);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_ctx *c)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	put_pct(c->mistakes, c->pairs);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(mode_name(c->mode), 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(mode_cplx(c->used), 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(total_ops(c), 2);
	ft_putstr_fd("\n", 2);
	put_counts(c);
}
