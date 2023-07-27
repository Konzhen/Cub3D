/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:16:39 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/25 22:39:50 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 256
#define HEIGHT 256

static mlx_image_t	*g_img;

void	hook(void* param)
{
	mlx_t* mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_P))
		mlx_delete_image(mlx, g_img);
	for (int x = 0; x < WIDTH; x++)
		for(int y= 0; y < HEIGHT / 2; y++)
			mlx_put_pixel(g_img, x, y, 0xFF0066);
	for (int x = 0; x < WIDTH; x++)
		for(int y= HEIGHT / 2; y < HEIGHT; y++)
			mlx_put_pixel(g_img, x, y, 0xBB0044);
}

int32_t	main(void)
{
	mlx_t*    mlx;
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, 256, 256);
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
