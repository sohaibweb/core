/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 10:09:34 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/09/20 13:48:04 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t			len;
	unsigned char	*a;
	char			*result;

	a = (unsigned char *)s;
	len = ft_strlen(s);
	result = malloc((sizeof(char) * len + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, a, len + 1);
	return (result);
}
