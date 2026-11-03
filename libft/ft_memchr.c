/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 10:00:56 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/09/20 20:22:39 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*a;
	unsigned char		b;

	a = (unsigned char *)s;
	b = c;
	i = 0;
	while (i < n)
	{
		if (a[i] == b)
		{
			return ((void *)&a[i]);
		}
		i++;
	}
	return (NULL);
}
