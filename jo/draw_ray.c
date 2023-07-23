/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:48:03 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/20 23:13:32 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libcub.h"

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
}
