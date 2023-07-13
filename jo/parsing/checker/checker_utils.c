/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:55:05 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/13 17:46:11 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libcub.h"  

static char*    get_texture_path(char *line, int *i)
{
    size_t  size;
    size_t     j;
    char    *tex_path;

    size = 0;
    j = *i;
    while (((line[j] < 7 || line[j] > 13) && line[j] != ' ') && line[j])
    {
        j++;
        size++;
    }
    tex_path = ft_calloc(size + 1, sizeof(char));
    if (!tex_path)
        return (NULL);
    j = 0;
    while (j < size)
    {
        tex_path[j] = line[*i];
        j++;
        (*i)++;
    }
    return (tex_path);
}

static char    *skip_empty_line(int fd)
{
    char    *line;
    
    line = get_next_line(fd);
    if (!line)
        return (NULL);
    if (!ft_strncmp(line, "EMPTY", 5))
    {
        free(line);
        return (NULL);
    }
    if (skip_spaces(line, NULL) == -1)
    {
        free(line);
        line = ft_strdup("EMPTY");
        return (line);
    }
    return (line);
}

bool    check_color_format(char *line, int *i, bool last)
{
    int color;

    skip_spaces(line, i);
    color = ft_atoi(&line[*i]);
    if (color < 0 || color > 255)
        return (false);
    while (line[*i] >= '0' && line[*i] <= '9')
        (*i)++;
    if (!last)
    {    
        if (line[*i] != ',')
            return (false);
    }
    (*i)++;
    return (true);
}

bool    check_texture_line(char *line, char *tex)
{
    char    *tex_path;
    int     tmp;
    int     i;

    i = 0;
    skip_spaces(line, &i);
    if (ft_strncmp(&line[i], tex, 3))
        return (false);
    i += 2;
    skip_spaces(line, &i);
    tex_path = get_texture_path(line, &i);
    if (!tex_path || check_ext(tex_path, ".jpg"))
    {
        free(tex_path);
        return (false);
    }
    tmp = open(tex_path, O_RDONLY);
    if (tmp == -1)
    {
        free(tex_path);
        return (false);
    }
    free(tex_path);
    close(tmp);
    return (true);
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