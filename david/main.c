/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:07:38 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/12 22:29:25 by dafranco         ###   ########.fr       */
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

static mlx_image_t* player;
static mlx_image_t* vision;
static mlx_image_t* line;
static float player_x;
static float player_y;
static float dir_x;
static float dir_y;
static float angle;

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

void ft_move(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		player->instances[0].x += dir_x;
		player->instances[0].y += dir_y;
		vision->instances[0].x = (player->instances[0].x + 10) + dir_x * 10;
		vision->instances[0].y = (player->instances[0].y + 10) + dir_y * 10;
	} 
	if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		player->instances[0].x -= dir_x;
		player->instances[0].y -= dir_y;
		vision->instances[0].x = (player->instances[0].x + 10) + dir_x * 10;
		vision->instances[0].y = (player->instances[0].y + 10)  + dir_y * 10;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		vision->instances[0].x = (player->instances[0].x + 10) + dir_x * 10;
		vision->instances[0].y = (player->instances[0].y + 10) + dir_y * 10;
		angle-=0.1;
		if(angle <= 0)
			angle += 2*PI;
		dir_x = cos(angle) * 3;
		dir_y = sin(angle) * 3;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		vision->instances[0].x = (player->instances[0].x + 10) + dir_x * 10;
		vision->instances[0].y = (player->instances[0].y + 10) + dir_y * 10;
		angle+=0.1;
		if(angle >= 2*PI)
			angle -= 2*PI;
		dir_x = cos(angle) * 3;
		dir_y = sin(angle) * 3;
	}
}

void	draw_player(t_vars *mlx)
{
	player = mlx_new_image(mlx->mlx_ptr, 30, 30);
	mlx_image_to_window(mlx->mlx_ptr, player, 300, 300);
	vision = mlx_new_image(mlx->mlx_ptr, 10, 10);
	mlx_image_to_window(mlx->mlx_ptr, vision, 300, 300);
}

int32_t	main(int argc, char **argv)
{
	t_vars	*mlx;

	(void)argc;
	mlx = malloc(sizeof(t_vars));
	mlx->map = map_len(argv[1]);
//	return (0);
	mlx->mlx_ptr = mlx_init(1024, 512, "MLX42", true);
	player_x = 0;
	player_y = 0;
	dir_x = cos(angle) * 5;
	dir_y = sin(angle) * 5;
	draw_map(*mlx);
	draw_player(mlx);
	line = mlx_new_image(mlx->mlx_ptr, 0, 0);
	mlx_image_to_window(mlx->mlx_ptr, line, 0, 0);
	mlx_loop_hook(mlx->mlx_ptr, draw_line, line);
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
