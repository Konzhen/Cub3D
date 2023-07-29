/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:12:53 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/28 18:11:37 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	draw_ext(t_data *data)
{
	data->background = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx_ptr, data->background, 0, 0);
}

void	draw_background(void *param)
{	
	mlx_image_t	*img;
	int			x;
	int			y;

	x = 0;
	y = 0;
	img = (mlx_image_t *)param;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(img, x, y, get_color_c(0, 0, 0, 1));
			else
				mlx_put_pixel(img, x, y, get_color_f(0, 0, 0, 1));
			++x;
		}
		x = 0;
		y++;
	}
}
