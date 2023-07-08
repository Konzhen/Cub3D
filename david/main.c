/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:07:38 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/07 23:49:04 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

static void	map_len(char *argv);
static char	**map_cpy(int fd, size_t x, size_t y);

int	main(int argc, char **argv)
{
	(void)argc;
	map_len(argv[1]);
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

static char	**map_cpy(int fd, size_t x, size_t y)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char **) * y);
	if (!map)
		return (NULL);
	while (i < (int)y)
	{
		map[i] = ft_calloc(sizeof(char *), x + 1);
		map[i] = strdup(get_next_line(fd));
		printf("%s", map[i]);
		i++;
	}
	return (map);
}

static void	map_len(char *argv)
{
	static size_t		x;
	static size_t		y;
	int					fd;
	char				*str;
	char				**map;

	fd = open(argv, O_RDONLY);
	str = NULL;
	map = NULL;
	while (1)
	{
		str = get_next_line(fd);
		if (ft_strlen(str) > x)
			x = ft_strlen(str);
		if (ft_strlen(str) == 0)
			break ;
		y++;
	}
	close(fd);
	fd = open(argv, O_RDONLY);
	map = map_cpy(fd, x, y);
	return ;
}
