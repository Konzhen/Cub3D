/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:55:05 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/07 16:04:32 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libcub.h"  

bool    check_color_format(char *line, int *i)
{
    int color;

    skip_spaces(line, i);
    color = ft_atoi(&line[*i]);
    if (color < 0 || color > 255)
    {
        free(line);
        return (false);
    }
    while (line[*i] >= '0' && line[*i] <= '9')
        (*i)++;
    if (line[*i] != ',')
    {
        free(line);
        return (false);
    }
    (*i)++;
    return (true);
}

bool    check_texture_line(char *line, char *tex, int fd)
{
    int tmp;
    int i;

    i = 0;
    skip_spaces(line, &i);
    if (ft_strncmp(&line[i], tex, 3))
        return (false);
    i += 2;
    skip_spaces(line, &i);
    tmp = open(&line[i], O_RDONLY);
    if (tmp == -1)
    {
        free(line);
        return (false);
    }
    close(tmp);
    free(line);
    line = get_next_valid_line(fd);
    if (!line)
        return (false);
    return (true);
}

char    *skip_empty_line(int fd)
{
    char    *line;

    line = get_next_valid_line(fd);
    if (!line)
        return (NULL);
    if (!skip_spaces(line, NULL))
    {
        free(line);
        return ("EMPTY");
    }
    return (line);
}

char    *get_next_valid_line(int fd)
{
    char    *line;

    line = skip_empty_line(fd);
    if (!line)
        return (NULL);
    while (!ft_strncmp(line, "EMPTY", 5))
    {
        free(line);
        line = skip_empty_line(fd);
        if (!line)
            return (NULL);
    }
    return (line);
}