/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-lata <yal-lata@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:39:37 by yal-lata          #+#    #+#             */
/*   Updated: 2026/11/03 15:39:38 by yal-lata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_putchar(char c)
{
	write(2, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putint(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		ft_putint(nb / 10);
	ft_putchar((nb % 10) + '0');
}

void	put_disorder(double ratio)
{
	int	result;

	result = (int)(ratio * 10000 + 0.5);
	ft_putint(result / 100);
	ft_putstr(".");
	if (result % 100 < 10)
		ft_putstr("0");
	ft_putint(result % 100);
	ft_putstr("%");
}

void	put_strategy(t_strategy strategy, t_list **stack, double ratio)
{
	ft_putstr("[bench] strategy: ");
	if (strategy == SIMPLE)
		ft_putstr("Simple / O(n^2)");
	else if (strategy == MEDIUM)
		ft_putstr("Medium / O(n sqrt n)");
	else if (strategy == COMPLEX)
		ft_putstr("Complex / O(n log n)");
	else
	{
		ft_putstr("Adaptive / ");
		ft_write_alg(ratio, stack);
	}
	ft_putstr("\n");
}
