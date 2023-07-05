/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:35:10 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/05 18:09:31 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libcub.h"

static bool check_texture(char *tex)
{
    int i;

    i = 0;

}

static bool check_valid_parameters(int fd)
{
    int i;
    
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
        return (false);
    return (true);
}