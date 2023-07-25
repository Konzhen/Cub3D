/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:41:32 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/25 17:48:59 by jbutte           ###   ########.fr       */
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
	get_hexa_color(r, g, b, 0);
	return (ft_strdup(get_hexa_color(r, g, b, 1)));
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
		if (fill_texture(map, line, dir))
		{
			free(line);
			return (true);
		}
		free(line);
		dir++;
	}
	return (false);
}

bool	set_map(t_map *map, int fd)
{
	if (set_textures(map, fd))
		return (true);
	map->color_f = set_colors(fd);
	if (!map->color_f)
		return (true);
	get_hexa_color(0, 0, 0, -1);
	map->color_c = set_colors(fd);
	if (!map->color_c)
		return (true);
	get_width_and_height(map);
	return (false);
}

t_map	*get_map(int fd, char *argv_1)
{
	t_map	*map;

	map = map_constructor();
	map->tab = get_tab(get_raw_tab(fd, argv_1));
	if (!map->tab)
	{
		free(map);
		return (NULL);
	}
	if (check_tab(map->tab))
	{
		free_map(map);
		err_std(ERR_TAB_NOT_VALID);
		return (NULL);
	}
	return (map);
}
