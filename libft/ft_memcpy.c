/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 10:02:57 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/09/20 20:10:33 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*sr;
	unsigned char		*det;

	i = 0;
	sr = src;
	det = dest;
	while (i < n)
	{
		det[i] = sr[i];
		i++;
	}
	return (det);
}
