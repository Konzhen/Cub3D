/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:12:53 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/23 22:44:37 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libcub.h"

static void	draw_all(void *mapcpy);

static mlx_image_t	*all;

void	draw_map(t_data mlx)
{
	all = mlx_new_image(mlx.mlx_ptr, HEIGHT, WIDTH);
	mlx_image_to_window(mlx.mlx_ptr, all, 50, 50);
	mlx_loop_hook(mlx.mlx_ptr, draw_all, mlx.map.tab);
}

static void	draw_all(void *mapcpy)
{
	uint32_t	x;
	uint32_t	y;
	char		**map = mapcpy;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '1')
				mlx_put_pixel(all, x, y, 0xBB00AA);
			++x;
		}
		++y;
		x = 0;
	}
}
