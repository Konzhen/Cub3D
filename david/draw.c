/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:12:53 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/27 20:41:18 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libcub.h"

void	draw_ext(t_data *data)
{
	data->background = mlx_new_image(data->mlx_ptr, HEIGHT, WIDTH);
	mlx_image_to_window(data->mlx_ptr, data->background, 0, 0);
	mlx_loop_hook(data->mlx_ptr, draw_background, data->background);
}

void	draw_background(void *param)
{	
	mlx_image_t	*img;
	int			x;
	int			y;

	x = 0;
	y = 0;
	img = param;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(img, x, y, 0xAAFFAA);
			else
				mlx_put_pixel(img, x, y, 0xFF0066);
			++x;
		}
		x = 0;
		y++;
	}
}
