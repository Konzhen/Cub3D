/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 04:43:43 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/24 05:14:53 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

bool	fill_texture(t_map *map, int fd, char *line, int tex_n)
{
	char	*tex_path;
	int		tmp;
	int		i;

	i = 0;
	skip_spaces(line, &i);
	i += 2;
	tex_path = get_texture_path(line, &i);
	if (!tex_path)
	{
		free(line);
		return (true);
	}
	if (tex_n == 1)
		map->no = tex_path;
	else if (tex_n == 2)
		map->so = tex_path;
	else if (tex_n == 3)
		map->we = tex_path;
	else if (tex_n == 4)
		map->ea = tex_path;
	return (false);
}

bool	set_colors(t_map *map, int fd)
{
	int	r;
	int	g;
	int	b;	
}

void	set_width_and_heigth(t_map *map)
{
	
}