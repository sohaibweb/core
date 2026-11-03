/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:00:00 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 15:00:00 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_ctx	c;

	if (argc < 2)
		return (0);
	init_ctx(&c);
	if (parse_args(argc, argv, &c) || check_duplicate(c.a))
		return (free_stack(c.a), write_error());
	if (!c.a)
		return (0);
	if (push_swap(&c))
		return (free_stack(c.a), free_stack(c.b), write_error());
	if (c.bench)
		print_bench(&c);
	free_stack(c.a);
	free_stack(c.b);
	return (0);
}
