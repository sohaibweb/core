/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 14:39:14 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/04 14:41:35 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int), 'x'));
	else if (c == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), 'X'));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

static int	ft_handle_char(const char *f, int *i, va_list args)
{
	if (f[*i] != '%')
		return (ft_putchar(f[*i]));
	if (!f[*i + 1])
		return (-1);
	(*i)++;
	return (ft_handle_format(f[*i], args));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		ret;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		ret = ft_handle_char(format, &i, args);
		if (ret == -1)
		{
			va_end(args);
			return (-1);
		}
		count += ret;
		i++;
	}
	va_end(args);
	return (count);
}
