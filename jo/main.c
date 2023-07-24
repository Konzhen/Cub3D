/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:07:38 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/24 03:01:34 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "libcub.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static char			**map_len(char *argv);
static char			**map_cpy(int fd, size_t x, size_t y);
static char			**map_init(char **blueprint, size_t y);

static mlx_image_t	*player;
static mlx_image_t	*line;
static float		player_x;
static float		player_y;
static float		dir_x;
static float		dir_y;
static float		angle;

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

void	ft_move(void *param)
{
	mlx_t	*data;

	data = param;
	if (mlx_is_key_down(data, MLX_KEY_W))
	{
		player->instances[0].x += dir_x;
		player->instances[0].y += dir_y;
		line->instances[0].x = (player->instances[0].x) + dir_x * 5;
		line->instances[0].y = (player->instances[0].y) + dir_y * 5;
	}
	if (mlx_is_key_down(data, MLX_KEY_S))
	{
		player->instances[0].x -= dir_x;
		player->instances[0].y -= dir_y;
		line->instances[0].x = (player->instances[0].x) + dir_x * 5;
		line->instances[0].y = (player->instances[0].y) + dir_y * 5;
	}
	if (mlx_is_key_down(data, MLX_KEY_A))
	{
		line->instances[0].x = (player->instances[0].x) + dir_x * 5;
		line->instances[0].y = (player->instances[0].y) + dir_y * 5;
		angle -= 0.1;
		if (angle <= 0)
			angle += 2 * PI;
		dir_x = cos(angle) * 3;
		dir_y = sin(angle) * 3;
	}
	if (mlx_is_key_down(data, MLX_KEY_D))
	{
		line->instances[0].x = (player->instances[0].x) + dir_x * 5;
		line->instances[0].y = (player->instances[0].y) + dir_y * 5;
		angle += 0.1;
		if (angle >= 2 * PI)
			angle -= 2 * PI;
		dir_x = cos(angle) * 3;
		dir_y = sin(angle) * 3;
	}
}

void	draw_player(t_vars *data)
{
	player = mlx_new_image(data->mlx_ptr, 10, 10);
	mlx_image_to_window(data->mlx_ptr, player, 300, 300);
}

int32_t	main(int argc, char **argv)
{
	t_vars	*data;
	/*int		fd;

	fd = checker(argv[1]);
	if (fd == -1)
		return (1);
	data = get_data(fd);
	if (!data)
		return (1);
	*/
	if (check_argc(argc, 2, 2))
		return (1);
	data = malloc(sizeof(t_vars));
	data->map = map_len(argv[1]);
	//	return (0);
	data->mlx_ptr = mlx_init(1024, 512, "MLX42", true);
	player_x = 0;
	player_y = 0;
	dir_x = cos(angle) * 5;
	dir_y = sin(angle) * 5;
	draw_map(*data);
	draw_player(data);

	line = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx_ptr, line, 200, 200);
	mlx_loop_hook(data->mlx_ptr, draw_line, line);
	mlx_loop_hook(data->mlx_ptr, ft_player, data->mlx_ptr);
	mlx_loop_hook(data->mlx_ptr, ft_move, data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
	mlx_terminate(data->mlx_ptr);
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
	static size_t	x;
	static size_t	y;
	int				fd;
	char			*str;
	char			**map;

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
