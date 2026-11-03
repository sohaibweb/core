/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:13:32 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/04 14:50:54 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, const char *base)
{
	int	count;
	int	ret;

	if (n >= 16)
	{
		count = ft_putnbr_base(n / 16, base);
		if (count == -1)
			return (-1);
	}
	else
		count = 0;
	ret = ft_putchar(base[n % 16]);
	if (ret != 1)
		return (-1);
	count += ret;
	return (count);
}

int	ft_putnbr_hex(unsigned int n, char format)
{
	if (format == 'X')
		return (ft_putnbr_base(n, "0123456789ABCDEF"));
	return (ft_putnbr_base(n, "0123456789abcdef"));
}

int	ft_putnbr_hex_ptr(unsigned long n)
{
	return (ft_putnbr_base(n, "0123456789abcdef"));
}
