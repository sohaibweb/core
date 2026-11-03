/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:13:42 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/04 15:13:38 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int				count;
	int				ret;
	unsigned long	n;

	if (!ptr)
		return (ft_putstr("(nil)"));
	n = (unsigned long)ptr;
	count = ft_putstr("0x");
	if (count == -1)
		return (-1);
	ret = ft_putnbr_hex_ptr(n);
	if (ret == -1)
		return (-1);
	return (count + ret);
}
