/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:12:53 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/10 12:04:24 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libcub.h"

static mlx_image_t	*all;

void	draw_map(void)
{
	t_vars	mlx;

	all = mlx_new_image(mlx.mlx_ptr, 100, 100);
	mlx_image_to_window(mlx.mlx_ptr, all, 0, 0);
	mlx_loop_hook(mlx.mlx_ptr, draw_all, mlx.mlx_ptr);
}

void	draw_all(void *param)
{
	uint32_t	x;
	uint32_t	y;
	char		**map;
	t_vars		cpy;

	(void)param;
	x = 0;
	y = 0;
	map = cpy.map;
	while (map[y])
	{
		while (*map[x])
		{
			if (map[y][x] == '1')
				mlx_put_pixel(all, y, x, 0xBB);
			else
				mlx_put_pixel(all, y, x, 0xBB00AA);
			++y;
		}
		++x;
		y = 0;
	}
}
