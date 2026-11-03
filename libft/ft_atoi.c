/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 08:03:59 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/09/16 19:35:19 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_skip_and_sign(const char *nptr, size_t *i, int *x)
{
	unsigned char	*str;

	str = (unsigned char *)nptr;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
	{
		(*i)++;
	}
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			*x *= -1;
		}
		(*i)++;
	}
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		x;
	long	r;

	i = 0;
	x = 1;
	r = 0;
	ft_skip_and_sign(nptr, &i, &x);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = r * 10 +(nptr[i] - '0');
		i++;
	}
	return (r * x);
}
