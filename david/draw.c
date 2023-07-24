/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:12:53 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/24 23:31:39 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libcub.h"

void	draw_ext(t_data *data)
{
	data->ceilling = malloc(sizeof(mlx_image_t));
	data->floor = malloc(sizeof(mlx_image_t));
	data->ceilling = mlx_new_image(data->mlx_ptr, HEIGHT, WIDTH);
	data->floor = mlx_new_image(data->mlx_ptr, HEIGHT, WIDTH);
	mlx_image_to_window(data->mlx_ptr, data->ceilling, 0, 0);
	mlx_image_to_window(data->mlx_ptr, data->floor, HEIGHT, WIDTH / 2);
	mlx_loop_hook(data->mlx_ptr, draw_ceilling, data->ceilling);
	mlx_loop_hook(data->mlx_ptr, draw_floor, data->floor);
}

void	draw_ceilling(void *arg)
{
	uint32_t	x;
	uint32_t	y;
	t_data		*data;

	data->ceilling = arg;
	x = 0;
	y = 0;
	while (y < HEIGHT / 2 && x < WIDTH)
	{
		while (x < WIDTH)
		{
			mlx_put_pixel(data->ceilling, x, y, ft_atoi(data->map.color_c));
			++x;
		}
		++y;
		if (y == HEIGHT / 2 && x == WIDTH)
			break ;
		x = 0;
	}
}

void	draw_floor(void *arg)
{
	uint32_t	x;
	uint32_t	y;
	t_data		*data;

	data->floor = arg;
	x = 0;
	y = 0;
	while (y < HEIGHT && x < WIDTH)
	{
		while (x < WIDTH)
		{
			mlx_put_pixel(data->floor, x, y, ft_atoi(data->map.color_f));
			++x;
		}
		++y;
		if (y == HEIGHT && x == WIDTH)
			break ;
		x = 0;
	}
}
