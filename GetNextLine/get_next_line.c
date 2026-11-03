/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 09:59:35 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/24 15:39:59 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_ret(char *a, char *b)
{
	free(a);
	free(b);
	return (NULL);
}

static char	*get_read_add(int fd, char *saved)
{
	char	*buf;
	char	*result;
	ssize_t	ret_fd;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free_ret(saved, NULL));
	while (!ft_strchr(saved, '\n'))
	{
		ret_fd = read(fd, buf, BUFFER_SIZE);
		if (ret_fd < 0)
			return (free_ret(buf, saved));
		if (ret_fd == 0)
			break ;
		buf[ret_fd] = '\0';
		result = ft_strjoin(saved, buf);
		if (!result)
			return (free_ret(buf, saved));
		free(saved);
		saved = result;
	}
	free(buf);
	return (saved);
}

static char	*get_line(char *saved)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = saved[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*init_saved(char *saved)
{
	if (saved)
		return (saved);
	saved = malloc(1);
	if (!saved)
		return (NULL);
	saved[0] = '\0';
	return (saved);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;
	char		*next_saved;
	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = init_saved(saved);
	if (!saved)
		return (NULL);
	saved = get_read_add(fd, saved);
	if (!saved)
		return (NULL);
	line = get_line(saved);
	next_saved = NULL;
	if (line)
		next_saved = get_cut(line, saved);
	free(saved);
	saved = next_saved;
	if (!saved)
		return (free_ret(line, NULL));
	return (line);
}
