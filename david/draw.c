/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:12:53 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/11 16:09:05 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libcub.h"

static mlx_image_t	*all;

void	draw_map(t_vars mlx)
{
	all = mlx_new_image(mlx.mlx_ptr, 1000, 1000);
	mlx_image_to_window(mlx.mlx_ptr, all, 0, 0);
	mlx_loop_hook(mlx.mlx_ptr, draw_all, mlx.map);
}

void	draw_all(void *mapcpy)
{
	uint32_t	x;
	uint32_t	y;
	char 		**map = mapcpy;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\n' && map[y][x] != '\0')
		{
			if (map[y][x] == '1')
				mlx_put_pixel(all, y, x, 0xBB);
			++x;
		}
		++y;
		x = 0;
	}
}
