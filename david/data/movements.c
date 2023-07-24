/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:47:19 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/24 07:36:02 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

void	move_forward(void *param)
{
	t_data	*data;
	char	**map;
	double	x;
	double	y;

	data = param;
	map = data->map.tab;
	x = data->player->info->instances[0].x + data->player->dir_x * 5;
	y = data->player->info->instances[0].y + data->player->dir_y * 5;
	if (data->map.tab[(int)x][(int)y] == '0'
			&& mlx_is_key_down(data->mlx_ptr, MLX_KEY_W))
	{
		data->player->info->instances[0].x += data->player->dir_x;
		data->player->info->instances[0].y += data->player->dir_y;
	}
}

void	move_backward(void *param)
{
	t_data	*data;
	char	**map;
	double	x;
	double	y;

	data = param;
	map = data->map.tab;
	x = data->player->info->instances[0].x - data->player->dir_x * 5;
	y = data->player->info->instances[0].y - data->player->dir_y * 5;
	if (data->map.tab[(int)x][(int)y] == '0'
		&& mlx_is_key_down(data->mlx_ptr, MLX_KEY_S))
	{
		data->player->info->instances[0].x -= data->player->dir_x;
		data->player->info->instances[0].y -= data->player->dir_y;
	}
}

void	move_left(void *param)
{
	t_data	*data;
	char	**map;

	data = param;
	map = data->map.tab;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_A))
	{
		data->player->angle -= 0.1;
		if (data->player->angle <= 2 * PI)
			data->player->angle += 2 * PI;
		data->player->dir_x = cos(data->player->angle) * 3;
		data->player->dir_y = sin(data->player->angle) * 3;
	}
}

void	move_right(void *param)
{
	t_data	*data;
	char	**map;

	data = param;
	map = data->map.tab;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_D))
	{
		data->player->angle += 0.1;
		if (data->player->angle >= 2 * PI)
			data->player->angle -= 2 * PI;
		data->player->dir_x = cos(data->player->angle) * 3;
		data->player->dir_y = sin(data->player->angle) * 3;
	}
}
