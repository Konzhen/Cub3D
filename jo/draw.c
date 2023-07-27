/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:12:53 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/27 20:10:13 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

static void	draw_ceilling(mlx_image_t *ceiling)
{
	uint32_t	x;
	uint32_t	y;

	x = 0;
	y = 0;
	while (y < HEIGHT / 2)
	{
		while (x < WIDTH)
		{
			mlx_put_pixel(ceiling, x, y,
				get_ceiling_color(0, 0, 0, false));
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_pixel()

	int i = 0x0;
}

static void	draw_floor(mlx_image_t *floor)
{
	uint32_t	x;
	uint32_t	y;

	x = 0;
	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			mlx_put_pixel(floor, x, y,
				get_floor_color(0, 0, 0, false));
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_floor_and_ceiling(t_data *data)
{
	mlx_image_to_window(data->mlx_ptr, data->ceilling, 0, 0);
	mlx_image_to_window(data->mlx_ptr, data->floor, HEIGHT, WIDTH / 2);
	mlx_loop_hook(data->mlx_ptr, draw_ceilling, data->ceilling);
	mlx_loop_hook(data->mlx_ptr, draw_floor, data->floor);
}
