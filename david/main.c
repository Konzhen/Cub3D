/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:07:38 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/11 01:05:55 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "libcub.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

static char	**map_len(char *argv);
static char	**map_cpy(int fd, size_t x, size_t y);
static char	**map_init(char **blueprint, size_t y);

static mlx_image_t* image;
static mlx_image_t* image2;
static mlx_image_t* player;
static mlx_image_t* vision;
static float player_x;
static float player_y;
static float dir_x;
static float dir_y;
static float angle;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void *param)
{
	(void)param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				0xBB, // R
				0xBB, // G
				0xBB, // B
				0xBB  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void	ft_cage(void *param)
{
	uint32_t	i;
	uint32_t	y;

	(void)param;
	i = 0;
	y = 0;
	while (i < image2->width)
	{
		while (y < image2->height)
		{
			mlx_put_pixel(image2, i, y, 0xBB00AA);
			++y;
		}
		++i;
		y = 0;
	}
}

void	ft_player(void *param)
{
	uint32_t	i;
	uint32_t	y;

	(void)param;
	i = 0;
	y = 0;
	while (i < player->width)
	{
		while (y < player->height)
		{
			mlx_put_pixel(player, i, y, 0xBB00AA);
			++y;
		}
		++i;
		y = 0;
	}
}

void	ft_vision(void *param)
{
	uint32_t	i;
	uint32_t	y;

	(void)param;
	i = 0;
	y = 0;
	while (i < vision->width)
	{
		while (y < vision->height)
		{
			mlx_put_pixel(vision, i, y, 0xBB00CC);
			++y;
		}
		++i;
		y = 0;
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

void ft_move(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		player->instances[0].x += dir_x;
		player->instances[0].y += dir_y;
		vision->instances[0].x += dir_x +3;
		vision->instances[0].y += dir_y +3;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		player->instances[0].x -= dir_x;
		player->instances[0].y -= dir_y;
		vision->instances[0].x -= dir_x -3;
		vision->instances[0].y -= dir_y -3;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		angle-=0.1;
		if(angle<0)
			angle += 2*PI;
		dir_x = cos(angle) * 5;
		dir_y = sin(angle) * 5;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		angle+=0.1;
		if(angle>2*PI)
			angle -= 2*PI;
		dir_x = cos(angle) * 5;
		dir_y = sin(angle) * 5;
	}
}

void	draw_player(t_vars *mlx)
{
	player = mlx_new_image(mlx->mlx_ptr, 30, 30);
	mlx_image_to_window(mlx->mlx_ptr, player, player_x, player_y);
	vision = mlx_new_image(mlx->mlx_ptr, 5, 20);
	mlx_image_to_window(mlx->mlx_ptr, vision, player_x + angle, player_y + angle);
}

int32_t	main(int argc, char **argv)
{
	t_vars	*mlx;

	(void)argc;
	mlx = malloc(sizeof(t_vars));
	mlx->map = map_len(argv[1]);
//	return (0);
	mlx->mlx_ptr = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	player_x = 100;
	player_y = 100;
	dir_x = cos(angle) * 5;
	dir_y = sin(angle) * 5;
	if (!(image = mlx_new_image(mlx->mlx_ptr, 9, 90)))
	{
		mlx_close_window(mlx->mlx_ptr);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx->mlx_ptr, image, 0, 0) == -1)
	{
		mlx_close_window(mlx->mlx_ptr);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	image2 = mlx_new_image(mlx->mlx_ptr, 90, 90);
	mlx_image_to_window(mlx->mlx_ptr, image2, 0, 0);
	draw_map(*mlx);
	draw_player(mlx);
	mlx_loop_hook(mlx->mlx_ptr, ft_randomize, mlx->mlx_ptr);
	mlx_loop_hook(mlx->mlx_ptr, ft_hook, mlx->mlx_ptr);
	mlx_loop_hook(mlx->mlx_ptr, ft_cage, mlx->mlx_ptr);
	mlx_loop_hook(mlx->mlx_ptr, ft_player, mlx->mlx_ptr);
	mlx_loop_hook(mlx->mlx_ptr, ft_vision, mlx->mlx_ptr);
	mlx_loop_hook(mlx->mlx_ptr, ft_move, mlx->mlx_ptr);
	mlx_loop(mlx->mlx_ptr);
	mlx_terminate(mlx->mlx_ptr);
	return (EXIT_SUCCESS);
}

static char	**map_init(char **blueprint, size_t y)
{
	char	**map;
	int		i;

	i = 0;
	while (i < (int)y)
	{
		fill_tab(blueprint, &map, y);
		i++;
	}
	i = 0;
	return (map);
}

static char	**map_cpy(int fd, size_t x, size_t y)
{
	char	**map;
	char	**cpy;
	int		i;

	i = 0;
	cpy = NULL;
	map = (char **)malloc((sizeof(char **) * y) + 1);
	if (!map)
		return (NULL);
	while (i < (int)y)
	{
		map[i] = ft_calloc(sizeof(char *), x);
		map[i] = strdup(get_next_line(fd));
		i++;
	}
	map[y + 1] = NULL;
	cpy = map_init(map, y);
	return (cpy);
}

static char	**map_len(char *argv)
{
	static size_t		x;
	static size_t		y;
	int					fd;
	char				*str;
	char				**map;

	fd = open(argv, O_RDONLY);
	str = NULL;
	map = NULL;
	while (1)
	{
		str = get_next_line(fd);
		if (ft_strlen(str) > x)
			x = ft_strlen(str);
		if (ft_strlen(str) == 0)
			break ;
		y++;
	}
	close(fd);
	fd = open(argv, O_RDONLY);
	map = map_cpy(fd, x, y);
	return (map);
}
