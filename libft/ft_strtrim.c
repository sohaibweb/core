/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 10:17:52 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/09/20 11:47:13 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_start_count(void)
{
	char	*result;

	result = malloc(sizeof(char));
	if (!result)
	{
		return (NULL);
	}
	result[0] = '\0';
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	i = 0;
	end = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			end = i + 1;
		i++;
	}
	if (start >= i)
		return (ft_start_count());
	return (ft_substr(s1, start, (end - start)));
}
