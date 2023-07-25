/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:47:19 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/24 05:34:03 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

void	move_forward(void *param)
{
	t_data	*data;
	mlx_t	*mlx;
	char	**map;
	double	next_x;
	double	next_y;

	mlx = param;
	map = data->map.tab;
	next_x = data->player->info->instances[0].x + data->player->dir_x * 5;
	next_x = data->player->info->instances[0].y + data->player->dir_y * 5;
	if (data->map.tab[(int)next_x][(int)next_y] == '0')
	{
		player->pos_x = next_x;
		player->pos_y = next_y;
		ray_k_string(map, player);
	}
}
	if(mlx_is_key_down(mlx, MLX_KEY_W))
	{

	}
}
