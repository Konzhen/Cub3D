/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:06:30 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/25 15:23:16 by jbutte           ###   ########.fr       */
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

static bool	get_data_player(t_data *data)
{
	data->player = player_constructor();
	if (!data->player)
		return (true);
	return (false);
}

static bool	get_data_player_ray(t_player *player)
{
	player->ray = ray_constructor();
	if (!player->ray)
		return (true);
	return (false);
}

static bool	get_data_ptr(t_data *data)
{
	data->mlx_ptr = mlx_init(1024, 512, "MLX42", true);
	if (!data->mlx_ptr)
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
