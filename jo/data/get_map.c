/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:41:32 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/24 04:40:43 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static bool	set_textures(t_map *map, int fd, char *line, int tex_n)
{
	char	*tex_path;
	int		tmp;
	int		i;

	i = 0;
	skip_spaces(line, &i);
	i += 2;
	tex_path = get_texture_path(line, &i);
	if (!tex_path)
		return (true);
	if (tex_n == 1)
		map->no = tex_path;
}

static bool	set_colors(t_map *map, int fd)
{

}

static void	set_width_and_heigth(t_map *map)
{
	
}

static bool	set_map(t_map *map)
{
	int		fd;
	bool	valid;
	char	*line;

	fd = open(argv_1, O_RDONLY);
	if (fd == -1)
	{
		err_std("can' t open the file");
		return (true);
	}
	valid = false;
	line = get_next_valid_line(fd);
	if (set_textures(&map, fd, line, 1) || set_textures(&map, fd, line, 2)
		set_textures(&map, fd, line, 3) || set_textures(&map, fd, line, 4))
		valid = true;
	if (set_colors(&map))
		valid = true;
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
		free_tab(map.tab);
		map = map_constructor();
		return (map);
	}
	return (map);
}