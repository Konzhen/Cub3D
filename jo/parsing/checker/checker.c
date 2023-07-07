/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:35:10 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/07 16:04:13 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libcub.h"

static bool check_colors(char *line, char *fc, int fd)
{
    int i;

    i = skip_spaces(line, NULL);
    if (ft_strncmp(&line[i], fc, 2))
    {
        free(line);
        return (false);
    }
    i++;
    if (!check_color_format(line, &i))
        return (false);
    if (!check_color_format(line, &i))
        return (false);
    if (!check_color_format(line, &i))
        return (false);
    line = get_next_valid_line(fd);
    if (!line)
        return (false);
    return (true);
}

static bool check_texture(char *line, int fd)
{
    if (!check_texture_line(line, "NO ", fd))
        return (false);
    if (!check_texture_line(line, "WE ", fd))
        return (false);
    if (!check_texture_line(line, "SO ", fd))
        return (false);
    if (!check_texture_line(line, "EA ", fd))
        return (false);
    return (true);
}

static bool check_valid_parameters(int fd)
{
    char    *line;

    line = get_next_valid_line(fd);
    if (!line)
        return (false);
    if (!check_texture(line, fd))
    {
        free(line);
        return (false);
    }
    if (!check_colors(line, "F ", fd) || !check_colors(line, "C ", fd))
    {
        free(line);
        return (false);
    }
    return (true);
}

bool    checker(char *argv_1)
{
    int fd;

    if (check_ext(argv_1, ".cub"))
        return (false);
    fd = open(argv_1, O_RDONLY);
        if (fd == -1)
            return (false);
    if (!check_valid_parameters(fd))
    {
        close(fd);
        printf("false");
        return (false);
    }
    return (true);
}
