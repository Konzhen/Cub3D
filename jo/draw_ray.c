/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:48:03 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/25 18:53:08 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libcub.h"

/*
void draw_line(void *param);

void draw_line(void *param)
{
	int	beginX = 10;
	int	beginY = 10;
	int	endX = 200;
	int	endY = 200;
	double deltaX = endX - beginX;
	double deltaY = endY - beginY;
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	double pixelY = beginY;
	double pixelX = beginX;
	while (pixels)
	{
	    mlx_put_pixel(param, pixelX, pixelY, 0xAA00AA);
	    pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}*/

void	shoot_ray(t_player *player, t_ray *rays)
{
	float tang;

	tang = 0;
	while(rays->ray < 90)
	{
		rays->offset = 0;
		tang = -1/tan(rays->angle);
		if (rays->angle > PI)
		{
			rays->dir_y = (((int)player->pos_y >> 6) << 6) - 0.0001;
			rays->dir_x = (player->pos_y - player->dir_y) * tang + player->pos_x;
			rays->side_y = -64;
			rays->side_x = rays->side_y*tang;
		}
		if (rays->angle < PI)
		{
			rays->dir_y = (((int)player->pos_y >> 6) << 6) + 64;
			rays->dir_x = (player->pos_y - player->dir_y) * tang + player->pos_x;
			rays->side_y = 64;
			rays->side_x = rays->side_y*tang;
		}
		if (rays->angle == 0 || rays->angle == PI)
		{
			rays->dir_x = player->pos_x;
			rays->dir_y = player->pos_y;
			rays->offset = 8;
		}
		while(rays->offset < 8)
		{
			rays->map_x = (int)rays->dir_x >> 6;
			rays->map_y = (int)rays->dir_y >> 6;
			rays->map_pos = rays->map_y*mapX + rays->map_x;
			if (rays->map_pos < map)
		}
	}
		rays->ray++;
}
