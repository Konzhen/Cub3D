/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:41:32 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/24 05:02:30 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static bool	set_textures(t_map *map, int fd)
{
	char	*line;

	line = get_next_valid_line(fd);
	if (!line || fill_texture(&map, fd, line, 1))
		return (true);
	free(line);
	line = get_next_valid_line(fd);
	if (!line || fill_texture(&map, fd, line, 2))
		return (true);
	free(line);
	line = get_next_valid_line(fd);
	if (!line || fill_texture(&map, fd, line, 3))
		return (true);
	if (fill_texture(&map, fd, line, 3))
		return (true);
	free(line);
	line = get_next_valid_line(fd);
	if (!line || fill_texture(&map, fd, line, 4))
		return (true);
	free(line);
	return (false);
}

static bool	set_map(t_map *map)
{
	int		fd;
	bool	valid;

	fd = open(argv_1, O_RDONLY);
	if (fd == -1)
	{
		err_std("can' t open the file");
		return (true);
	}
	valid = false;
	if (set_textures(&map, fd))
		return (true);
	if (set_colors(&map))
		return (true);
	set_width_and_heigth(&map);
	return (map);
}

t_map	*get_map(int fd, char *argv_1)
{
	t_map	*map;
	char	**tab;

	map = map_constructor();
	map.tab = get_tab(get_raw_tab(fd, argv_1));
	if (!map.tab || check_tab(map.tab))
		return (map);
	if (set_map(&map))
	{
		free_map(&map);
		map = map_constructor();
		return (map);
	}
	return (map);
}