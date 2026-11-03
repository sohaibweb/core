/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 10:11:28 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/09/17 14:22:12 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		if (size > 0 && i + 1 < size)
			dst[i] = src[i];
		i++;
	}
	if (size > 0)
	{
		if (i >= size)
			dst[size - 1] = '\0';
		else
			dst[i] = '\0';
	}
	return (i);
}
