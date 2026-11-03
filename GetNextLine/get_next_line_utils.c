/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 09:59:35 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/11 09:59:36 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	src_len = ft_strlen(src);
	if (dst_len == size)
		return (size + src_len);
	i = 0;
	while (src[i] && dst_len + i + 1 < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	result[0] = '\0';
	ft_strlcat(result, s1, len1 + len2 + 1);
	ft_strlcat(result, s2, len1 + len2 + 1);
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*get_cut(char *line, char *saved)
{
	size_t	i;
	size_t	j;
	size_t	line_len;
	size_t	saved_len;
	char	*result;

	line_len = ft_strlen(line);
	saved_len = ft_strlen(saved);
	if (saved_len < line_len)
		return (NULL);
	i = line_len;
	result = malloc(saved_len - line_len + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (i < saved_len)
		result[j++] = saved[i++];
	result[j] = '\0';
	return (result);
}
