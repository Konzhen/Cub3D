/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:06:30 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/24 18:13:10 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static bool	set_data_map(t_data *data, int fd, char *argv_1)
{
	data->map = get_map_tab(fd, argv_1);
	if (!data->map)
	{
		close(fd);
		free_map(data->map);
		free(data);
		return (true);
	}
	close(fd);
	fd = open(argv_1, O_RDONLY);
	if (fd == -1)
	{
		err_std(ERR_CUB_FILE);
		return (-1);
	}
	if (set_map(data->map, fd))
	{
		close(fd);
		free_map(data->map);
		free(data);
		return (true);
	}
	return (false);
}

t_data	*get_data(int fd, char *argv_1)
{
	t_data	*data;

	data = calloc2(1, sizeof(t_data));
	if (!data || set_data_map(data, fd, argv_1))
	{
		return (NULL);
	}
	close(fd);
	return (data);
}