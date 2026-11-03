/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 14:09:57 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/09/29 14:25:07 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(const char *s);
int	ft_putnbr(int n);
int	ft_putptr(void *ptr);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putnbr_base(unsigned long n, const char *base);
int	ft_putnbr_hex(unsigned int n, char format);
int	ft_putnbr_hex_ptr(unsigned long n);
int	ft_printf(const char *format, ...);
#endif
