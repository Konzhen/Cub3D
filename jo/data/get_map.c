/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:41:32 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/26 17:46:41 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static bool	set_colors(int fd, bool floor)
{
	char	*line;
	int		i;
	int		r;
	int		g;
	int		b;

	line = get_next_valid_line(fd);
	if (!line)
		return (true);
	i = skip_spaces(line, NULL);
	i++;
	r = get_color_value(line, &i);
	g = get_color_value(line, &i);
	b = get_color_value(line, &i);
	free(line);
	if (floor)
		get_floor_color(r, g, b, 0);
	else
		get_ceiling_color(r, g, b, 0);
	return (false);
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
	if (set_colors(fd, true))
		return (true);
	if (set_colors(fd, false))
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
