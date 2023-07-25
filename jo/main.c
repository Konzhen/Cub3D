/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:07:38 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/25 15:23:15 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "libcub.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static mlx_image_t	*player;
static float		player_x;
static float		player_y;
static float		dir_x;
static float		dir_y;
static float		angle;

void	ft_player(void *param)
{
	uint32_t	i;
	uint32_t	y;

	(void)param;
	i = 0;
	y = 0;
	while (i < player->width)
	{
		while (y < player->height)
		{
			mlx_put_pixel(player, i, y, 0xBB00AA);
			++y;
		}
		++i;
		y = 0;
	}
}

void	ft_move(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		player->instances[0].x += dir_x;
		player->instances[0].y += dir_y;
		line->instances[0].x = (player->instances[0].x) + dir_x * 5;
		line->instances[0].y = (player->instances[0].y) + dir_y * 5;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		player->instances[0].x -= dir_x;
		player->instances[0].y -= dir_y;
		line->instances[0].x = (player->instances[0].x) + dir_x * 5;
		line->instances[0].y = (player->instances[0].y) + dir_y * 5;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		line->instances[0].x = (player->instances[0].x) + dir_x * 5;
		line->instances[0].y = (player->instances[0].y) + dir_y * 5;
		angle -= 0.1;
		if (angle <= 0)
			angle += 2 * PI;
		dir_x = cos(angle) * 3;
		dir_y = sin(angle) * 3;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		line->instances[0].x = (player->instances[0].x) + dir_x * 5;
		line->instances[0].y = (player->instances[0].y) + dir_y * 5;
		angle += 0.1;
		if (angle >= 2 * PI)
			angle -= 2 * PI;
		dir_x = cos(angle) * 3;
		dir_y = sin(angle) * 3;
	}
}

void	draw_player(t_data *data)
{
	player = mlx_new_image(data->mlx_ptr, 10, 10);
	mlx_image_to_window(data->mlx_ptr, player, 300, 300);
}

int32_t	main(int argc, char **argv)
{
	t_data	*data;
	int		fd;
	
	if (check_argc(argc, 2, 2))
		return (1);
	fd = checker(argv[1]);
	if (fd == -1)
		return (1);
	data = get_data(fd, argv[1]);
	if (!data)
		return (1);
	init_game(data);
	player_x = 0;
	player_y = 0;
	dir_x = cos(angle) * 5;
	dir_y = sin(angle) * 5;
	draw_map(*data);
	draw_player(data);
	// if (!mlx->map)
	//	return (1);
	mlx_loop_hook(data->mlx_ptr, ft_player, data->mlx_ptr);
	mlx_loop_hook(data->mlx_ptr, ft_move, data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
	mlx_terminate(data->mlx_ptr);
	return (EXIT_SUCCESS);
}
