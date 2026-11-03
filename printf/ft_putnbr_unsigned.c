/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:13:00 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/04 14:49:50 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;
	int	ret;

	count = 0;
	if (n >= 10)
	{
		count = ft_putnbr_unsigned(n / 10);
		if (count == -1)
			return (-1);
	}
	ret = ft_putchar((n % 10) + '0');
	if (ret != 1)
		return (-1);
	count += ret;
	return (count);
}
