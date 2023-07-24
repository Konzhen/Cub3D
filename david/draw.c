/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:12:53 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/24 08:43:17 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libcub.h"

static void	draw_all(void *mapcpy);

static mlx_image_t	*all;

void	draw_map(t_data *data)
{
	all = mlx_new_image(data->mlx_ptr, HEIGHT, WIDTH);
	mlx_image_to_window(data->mlx_ptr, all, 50, 50);
	mlx_loop_hook(data->mlx_ptr, draw_all, data);
}

static void	draw_all(void *mapcpy)
{
	uint32_t	x;
	uint32_t	y;
	t_data		*data;

	x = 0;
	y = 0;
	data = (t_data *)mapcpy;
	while (data->map.tab[y])
	{
		while (data->map.tab[y][x] != '\0')
		{
			if (data->map.tab[y][x] == '1')
				mlx_put_pixel(all, x, y, 0xBB00AA);
			++x;
		}
		++y;
		x = 0;
	}
}
