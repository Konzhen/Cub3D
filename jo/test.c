#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 256
#define HEIGHT 256



void	draw_background(void* param)
{	
	mlx_image_t	*img;
	int	x;
	int	y;

	x = 0;
	y = 0;
	img = param;
	while(y < HEIGHT / 2)
	{
		while(x < WIDTH)
		{
			mlx_put_pixel(img, x, y ,0xAAFFAA);
			++x;
		}
		x = 0;
		y++;
	}
	while(y < HEIGHT)
	{
		while(x < WIDTH)
		{
			mlx_put_pixel(img, x, y ,0xFF0066);
			++x;
		}
		x = 0;
		y++;
	}
}

int32_t	main(void)
{
	mlx_image_t	*background;
	mlx_t*    mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "test_background", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	background = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, background, 0, 0);
	mlx_loop_hook(mlx, &draw_background, background);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
