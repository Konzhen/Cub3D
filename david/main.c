/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:07:38 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/08 20:58:39 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static char	**map_len(char *argv);
static char	**map_cpy(int fd, size_t x, size_t y);
static char	**map_init(char **blueprint, size_t y);

static mlx_image_t* image;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	(void)param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
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

int32_t	main(int argc, char **argv)
{
	t_vars	ptr;

	(void)argc;
	(void)argv;
	ptr.map = map_len(argv[1]);
//	return (0);
	mlx_t* mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 128, 128)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

static char	**map_init(char **blueprint, size_t y)
{
	char	**map;
	int		i;

	i = 0;
	map = NULL;
	while (blueprint[i])
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
	map = (char **)malloc((sizeof(char *) * y) + 1);
	if (!map)
		return (NULL);
	while (i < (int)y)
	{
		map[i] = ft_calloc(sizeof(char *), x + 1);
		map[i] = strdup(get_next_line(fd));
		i++;
	}
	map[i] = NULL;
	cpy = map_init(map, y);
	return (map);
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
