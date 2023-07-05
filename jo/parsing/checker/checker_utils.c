/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:55:05 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/05 18:09:31 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libcub.h"

char    *skip_empty_line(int fd)
{
    char    *line;
    int     i;

    line = get_next_line(fd);
    if (!line)
        return (NULL);
    i = 0;
    skip_spaces(line, i);
    if (!ft_strncmp(line[i], "\n", ft_strlen(&line[i])))
    {
        free(line);
        return ("E");
    }
    return (line);
}