/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:06:30 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/27 20:31:04 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static bool	get_data_map(t_data *data, int fd, char *argv_1)
{
	data->map = get_map(fd, argv_1);
	if (!data->map)
	{
		close(fd);
		return (true);
	}
	close(fd);
	fd = open(argv_1, O_RDONLY);
	if (fd == -1)
	{
		err_std(ERR_CUB_FILE);
		return (true);
	}
	if (set_map(data->map, fd))
	{
		close(fd);
		return (true);
	}
	close(fd);
	return (false);
}

static bool	get_data_player_ray(t_player *player)
{
	player->ray = ray_constructor();
	if (!player->ray)
		return (true);
	return (false);
}

static bool	get_data_player(t_data *data)
{
	data->player = get_player(data->map->tab);
	if (!data->player)
		return (true);
	data->player->info = mlx_new_image(data->mlx_ptr, 10, 10);
	if (!data->player->info)
		return (true);
	mlx_image_to_window(data->mlx_ptr, data->player,
		data->player->pos_x * 10, data->player->pos_y * 10);
	return (false);
}

static bool	get_data_ptr(t_data *data)
{
	data->mlx_ptr = mlx_init(1024, 512, "MLX42", true);
	if (!data->mlx_ptr)
		return (true);
	data->ceilling = mlx_new_image(data->mlx_ptr, HEIGHT, WIDTH);
	if (!data->ceilling)
		return (true);
	data->floor = mlx_new_image(data->mlx_ptr, HEIGHT, WIDTH);
	if (!data->floor)
		return (true);
	return (false);
}

t_data	*get_data(int fd, char *argv_1)
{
	t_data	*data;

	data = data_constructor();
	if (!data)
	{
		close(fd);
		return (NULL);
	}
	if (get_data_ptr(data) || get_data_map(data, fd, argv_1)
		|| get_data_player(data) || get_data_player_ray(data->player))
	{	
		free_data(data);
		return (NULL);
	}
	return (data);
}
