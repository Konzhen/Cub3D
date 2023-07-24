/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:41:32 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/24 18:01:44 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static char	*set_colors(int fd)
{
	char	*line;
	int		i;
	int		r;
	int		g;
	int		b;

	line = get_next_valid_line(fd);
	if (!line)
		return (NULL);
	i = skip_spaces(line, NULL);
	i++;
	r = get_color_value(line, &i);
	g = get_color_value(line, &i);
	b = get_color_value(line, &i);
	free(line);
	return (ft_strdup(stocker_color(r, g, b, 0)));
}

static bool	set_textures(t_map *map, int fd)
{
	char	*line;
	int		dir;

	dir = 0;
	while (dir < 4)
	{
		line = get_next_valid_line(fd);
		if (!line)
			return (true);
		if (fill_texture(&map, fd, line, dir))
		{
			free(line);
			return (true);
		}
		free(line);
		dir++;
	}
	return (false);
}

static bool	set_map(t_map *map, int fd)
{
	if (set_textures(map, fd))
		return (true);
	map->color_f = set_colors(fd);
	if (!map->color_f)
		return (true);
	map->color_c = set_colors(fd);
	if (!map->color_c)
		return (true);
	set_width_and_heigth(map);
	return (false);
}

t_map	*get_map_tab(int fd, char *argv_1)
{
	t_map	*map;
	char	**tab;

	map = map_constructor();
	map->tab = get_tab(get_raw_tab(fd, argv_1));
	if (!map->tab)
	{
		free(map);
		return (NULL);
	}
	if (check_tab(map->tab))
	{
		free_tab((void **)map->tab, 0);
		free(map);
		err_std(ERR_TAB_NOT_VALID);
		return (NULL);
	}
	return (map);
}
