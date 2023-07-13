/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:35:10 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/13 17:45:24 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libcub.h"

static bool check_colors(char *line, char *fc)
{
    int i;

    i = skip_spaces(line, NULL);
    if (ft_strncmp(&line[i], fc, 2))
        return (false);
    i++;
    if (!check_color_format(line, &i, false))
        return (false);
    if (!check_color_format(line, &i, false))
        return (false);
    if (!check_color_format(line, &i, true))
        return (false);
    free(line);
    return (true);
}

static bool check_texture(char *line, int fd)
{
    bool    valid;

    valid = true;
    if (!check_texture_line(line, "NO "))
        valid = false;
    free(line);
    line = get_next_valid_line(fd);
    if (!line)
        return (false);
    if (!check_texture_line(line, "SO "))
        valid = false;
    free(line);
    line = get_next_valid_line(fd);
    if (!line)
        return (false);
    if (!check_texture_line(line, "WE "))
        valid = false;
    free(line);
    line = get_next_valid_line(fd);
    if (!line)
        return (false);
    if (!check_texture_line(line, "EA "))
        valid = false;
    free(line);
    return (valid);
}

static bool check_valid_parameters(int fd, char *line)
{
    if (!check_texture(line, fd))
        return (false);
    line = get_next_valid_line(fd);
    if (!line)
        return (false);
    if (!check_colors(line, "F "))
    {
        free(line);
        return (false);
    }
    line = get_next_valid_line(fd);
    if (!line)
        return (false);
    if (!check_colors(line, "C "))
    {
        free(line);
        return (false);
    }
    return (true);
}

bool    checker(char *argv_1)
{
    int     fd;
    char    *line;

    if (check_ext(argv_1, ".cub"))
        return (false);
    fd = open(argv_1, O_RDONLY);
        if (fd == -1)
            return (false);
    line = get_next_valid_line(fd);
    if (!line || !check_valid_parameters(fd, line))
    {
        close(fd);
        printf("false");
        return (false);
    }
    return (true);
}
