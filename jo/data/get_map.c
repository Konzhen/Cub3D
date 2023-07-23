/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:41:32 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/23 22:53:47 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static bool	set_textures(t_map *map, int fd)
{

}

static bool	set_colors(t_map *map, int fd)
{

}

static bool	set_width_and_heigth(t_map *map)
{
	
}

static bool	set_map(t_map *map, t)
{
	int		fd;
	bool	valid;

	fd = open(argv_1, O_RDONLY);
	if (fd == -1)
	{
		err_std("can' t open the file");
		return (NULL);
	}
	valid = false;
	if (set_textures(map))
		valid = true;
}

t_map	get_map(char *argv_1)
{
	t_map	map;
	char	**tab;

	map = map_constructor();
	tab = check_and_get_tab(argv_1);
	if (!tab)
		return (map);
	if (set_map(&map))
	{
		
		map = map_constructor();
		return (map);
	}
	return (map);
}