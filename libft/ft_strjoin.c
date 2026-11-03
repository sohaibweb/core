/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 10:10:33 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/09/22 12:09:46 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	len_s1;
	size_t	len_s2;
	char	*result;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len = len_s1 + len_s2;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[0] = '\0';
	ft_strlcat(result, s1, len + 1);
	ft_strlcat(result, s2, len + 1);
	return (result);
}
