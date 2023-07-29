/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:48:15 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/28 17:57:44 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

t_map	*map_constructor(void)
{
	t_map	*map;

	map = calloc2(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->tab = NULL;
	map->width = 0;
	map->height = 0;
	return (map);
}

t_player	*player_constructor(void)
{
	t_player	*player;

	player = calloc2(1, sizeof(t_player));
	if (!player)
		return (NULL);
	player->start = 0;
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->lvl_x = 0.0;
	player->lvl_y = 0.0;
	player->ray = NULL;
	return (player);
}

t_ray	*ray_constructor(void)
{
	t_ray	*ray;

	ray = calloc2(1, sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->size = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->side_x = 0;
	ray->side_y = 0;
	return (ray);
}

t_data	*data_constructor(void)
{
	t_data	*data;

	data = calloc2(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->background = NULL;
	data->mlx_ptr = NULL;
	data->title = NULL;
	data->map = NULL;
	data->player = NULL;
	return (data);
}
