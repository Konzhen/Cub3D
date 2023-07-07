/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:07:38 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/07 18:09:00 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

static char	**map_len(int fd);

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char **map;
	int fd = open("test.txt", O_RDONLY);
	map = map_len(fd);
	return(0);
}
/*
static ssize_t get_mapsize_y(const char **blueprint)
{
	ssize_t	i;

	i = 0;
	return (i);
}

static ssize_t get_mapsize_x(const char *blueprint, int fd)
{
	ssize_t	i;

	i = 0;
	while (blueprint[i] && blueprint[i] != '\n')
		i++;
	return (i);
}
*/

static char	**map_len(int fd)
{
	static size_t		x;
	static size_t		y;
	char			*str = NULL;
	char			**map = NULL;

	while (1)
	{
		str = get_next_line(fd);
		if (ft_strlen(str) > x)
			x = ft_strlen(str);
		if (ft_strlen(str) == 0)
			break ;
		y++;
	}
	printf("x = %lu\ny = %lu\n", x, y);
	return (map);
}
