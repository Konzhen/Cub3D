/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 04:43:43 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/25 14:53:49 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

int	get_color_value(char *line, int *i)
{
	int	color;

	skip_spaces(line, i);
	color = ft_atoi(&line[*i]);
	while (line[*i] >= '0' && line[*i] <= '9')
		(*i)++;
	skip_spaces(line, i);
	(*i)++;
	return (color);
}

bool	fill_texture(t_map *map, int fd, char *line, int dir)
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
	if (dir == 0)
		map->no = tex_path;
	else if (dir == 1)
		map->so = tex_path;
	else if (dir == 2)
		map->we = tex_path;
	else if (dir == 3)
		map->ea = tex_path;
	return (false);
}

void	set_width_and_height(t_map *map)
{
	int	y;
	int	x;
	int	max_width;

	y = 0;
	x = 0;
	max_width = 0;
	while (map->tab[y])
	{
		while (map->tab[y][x] != '\n' && map->tab[y][x])
			x++;
		if (x > max_width)
			max_width = x;
		x = 0;
		y++;
	}
	map->width = max_width;
	map->height = y;
}
