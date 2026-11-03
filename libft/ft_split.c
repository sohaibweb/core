/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 12:51:20 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/09/23 13:43:09 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	count;

	i = 0;
	count = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i != j)
			count++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static void	ft_free_result(char **result, size_t idx_word)
{
	while (idx_word > 0)
	{
		idx_word--;
		free(result[idx_word]);
	}
}

static int	ft_add_word(char const *s, char c, char **result, size_t *i)
{
	size_t	j;

	j = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	if (*i != j)
	{
		*result = ft_substr(s, j, *i - j);
		if (!*result)
			return (0);
	}
	else
		*result = NULL;
	return (1);
}

static int	ft_fill_split(char const *s, char c, char **result)
{
	size_t	i;
	size_t	idx_word;

	i = 0;
	idx_word = 0;
	while (s[i])
	{
		if (!ft_add_word(s, c, &result[idx_word], &i))
		{
			ft_free_result(result, idx_word);
			return (0);
		}
		if (result[idx_word])
			idx_word++;
		while (s[i] && s[i] == c)
			i++;
	}
	result[idx_word] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		success;
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!result)
		return (NULL);
	success = ft_fill_split(s, c, result);
	if (!success)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
