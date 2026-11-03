/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:00:00 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 15:00:00 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(long long n, int fd)
{
	char	c;

	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = '0' + n % 10;
	write(fd, &c, 1);
}

void	put_pct(long long mistakes, long long pairs)
{
	long long	v;

	v = 0;
	if (pairs > 0)
		v = (mistakes * 10000 + pairs / 2) / pairs;
	ft_putnbr_fd(v / 100, 2);
	ft_putstr_fd(".", 2);
	if (v % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(v % 100, 2);
	ft_putstr_fd("%\n", 2);
}
