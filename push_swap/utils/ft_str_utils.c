/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 11:19:51 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/27 12:22:29 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	write_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	ft_strlen(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static void	ft_skip_and_sign(const char *nptr, size_t *i, int *x)
{
	const unsigned char	*str;

	str = (const unsigned char *)nptr;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*x *= -1;
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
		r = r * 10 + (nptr[i++] - '0');
	return (r * x);
}

void	ft_write_alg(double n, t_list **stack)
{
	int	size;

	size = ft_lstsize(*stack);
	if (size == 2)
		ft_putstr("sort_two");
	else if (size == 3)
		ft_putstr("sort_three");
	else if (size > 3 && size <= 5)
		ft_putstr("sort_five");
	else if (n < 0.2)
		ft_putstr("O(n^2)");
	else if (n < 0.5)
		ft_putstr("O(n√n)");
	else
		ft_putstr("O(n log n)");
}
