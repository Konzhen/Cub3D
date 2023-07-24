/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:07:38 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/24 08:59:40 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "libcub.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void	ft_player(void *param)
{
	t_data		data;
	uint32_t	i;
	uint32_t	y;

	(void)param;
	i = 0;
	y = 0;
	while (i < data.player->info->width)
	{
		while (y < data.player->info->height)
		{
			mlx_put_pixel(data.player->info, i, y, 0xBB00AA);
			++y;
		}
		++i;
		y = 0;
	}
}

void	draw_player(t_data data)
{
	mlx_image_t		*player;

	data.player = malloc(sizeof(t_player));
	player = NULL;
	data.player->angle = 0.0;
	data.player->dir_x = 0.0;
	data.player->dir_y = 0.0;
	data.player->dir_x = cos(data.player->angle) * 5;
	data.player->dir_y = sin(data.player->angle) * 5;
	data.player->pos_x = 0.0;
	data.player->pos_y = 0.0;
	data.player->info = player;
	player = mlx_new_image(data.mlx_ptr, 10, 10);
	mlx_image_to_window(data.mlx_ptr, player, 300, 300);
}

int32_t	main(int argc, char **argv)
{
	t_data	*data;

	if (check_argc(argc, 2, 2))
		return (1);
	data = malloc(sizeof(t_data));
//	fd = checker(argv[1]);
//	if (fd == -1)
//		return (1);
//	data = get_data(fd);
//	if (!data)
//		return (1);
	data->map->tab = checker(argv[1]);
	init_game(data);
	draw_player(*data);
	draw_map(data);
	ft_loops(data);
	mlx_terminate(data->mlx_ptr);
	return (EXIT_SUCCESS);
}
