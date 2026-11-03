/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 10:10:54 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/09/20 12:02:14 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t				i;
	size_t				n;
	size_t				j;

	i = 0;
	n = ft_strlen(src);
	while (i < size && dst[i])
		i++;
	j = i;
	if (size == 0 || j == size)
		return (n + j);
	i = 0;
	while (src[i] && j + i + 1 < size)
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (j + n);
}
