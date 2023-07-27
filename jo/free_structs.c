/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 05:02:45 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/25 22:45:41 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->tab)
		free_tab((void **)map->tab, 0);
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	free(map);
}

void	free_player(t_player *player)
{
	if (!player)
		return ;
	if (player)
	{
		if (player->ray)
			free(player->ray);
		free(player);
	}
}

void	free_data(t_data *data)
{
	/*if (data->mlx_ptr)
	{
		mlx_terminate(data->mlx_ptr);
		free(data->mlx_ptr);
	}*/
	if (data->title)
		free(data->title);
	if (data->map)
		free_map(data->map);
	if (data->player)
		free_player(data->player);
	free(data);
}
