/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 10:20:48 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/07 10:22:09 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_read_add(int fd, char *saved)
{
    char    *buf;
    int     ret_fd;
    char    *result;

    while (!(ft_strchr(saved, '\n')))
    {
        ret_fd = read(fd, buf, BUFFER_SIZE);
        if (ret_fd < 0)
            return(NULL);
        if (ret_red == 0)
            break ;
        result = ft_strjoin(saved, buf);
    }
}
char    *get_line(int fd, char *sav)
{
    int     i;
    int     j;
    char    *result;

    i = 0;
    while(sav[i] != '\n')
        i++;
    result = malloc(i + 2);
    if (!result)
        return(NULL);
    i = 0;
    j = 0;
    while(sav[i])
    {
        if (sav[i] != '\n')
            result[j] = sav[i];
        i++;
        j++;
    }
    result[i++] = '\n';
    result[i] = '\0';
    return (result);
}
char *init_sav(char * sav)
{
    if (sav)
        return(sav);
    sav = malloc(1);
    sav = '\0';
    return(sav);
}

char	*get_next_line(int fd)
{
    static char *saved;
    char        *line;

    saved = get_read_add(fd, saved);
}