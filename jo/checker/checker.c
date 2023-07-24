/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:35:10 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/24 04:14:50 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static bool	check_colors(char *line, char *fc)
{
	int	i;

	i = skip_spaces(line, NULL);
	if (ft_strncmp(&line[i], fc, 1))
		return (err_std("invalid color format\n"));
	i++;
	if ((line[i] < 7 || line[i] > 13) && line[i] != ' ')
		return (true);
	if (check_color_format(line, &i, false))
		return (true);
	if (check_color_format(line, &i, false))
		return (true);
	if (check_color_format(line, &i, true))
		return (true);
	if (check_residue(&line[i]))
		return (err_std("invalid color format\n"));
	free(line);
	return (false);
}

static bool	check_texture(char *line, int fd)
{
	bool	is_valid;

	is_valid = false;
	if (check_texture_line(line, "NO", 1))
		is_valid = true;
	free(line);
	line = get_next_valid_line(fd);
	if (!line)
		return (true);
	if (check_texture_line(line, "SO", 2))
		is_valid = true;
	free(line);
	line = get_next_valid_line(fd);
	if (!line)
		return (true);
	if (check_texture_line(line, "WE", 3))
		is_valid = true;
	free(line);
	line = get_next_valid_line(fd);
	if (!line)
		return (true);
	if (check_texture_line(line, "EA", 4))
		is_valid = true;
	free(line);
	return (is_valid);
}

static bool	check_valid_parameters(int fd)
{
	char	*line;

	line = get_next_valid_line(fd);
	if (!line)
		return (true);
	if (check_texture(line, fd))
		return (true);
	line = get_next_valid_line(fd);
	if (!line)
		return (true);
	if (check_colors(line, "F"))
	{
		free(line);
		return (true);
	}
	line = get_next_valid_line(fd);
	if (!line)
		return (true);
	if (check_colors(line, "C"))
	{
		free(line);
		return (true);
	}
	return (false);
}

int	checker(char *argv_1)
{
	int		fd;

	if (check_ext(argv_1, ".cub"))
		return (-1);
	fd = open(argv_1, O_RDONLY);
	if (fd == -1)
	{
		err_std("can' t open the file");
		return (-1);
	}
	if (check_valid_parameters(fd))
	{
		close(fd);
		return (-1);
	}
	return (fd);
}
