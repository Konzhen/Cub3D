/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:35:10 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/24 11:57:58 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static bool	check_colors(char *line, char *fc)
{
	int	i;

	i = skip_spaces(line, NULL);
	if (ft_strncmp(&line[i], fc, 1))
		return (err_std(ERR_COLOR_FORMAT));
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
		return (err_std(ERR_COLOR_FORMAT));
	free(line);
	return (false);
}

static bool	check_texture(char *line, int fd)
{
	int	dir;

	dir = 0;
	if (check_texture_line(line, dir))
	{
		free(line);
		return (true);
	}
	free(line);
	dir++;
	while (dir < 4)
	{
		line = get_next_valid_line(fd);
		if (!line)
			return (true);
		if (check_texture_line(line, dir))
		{
			free(line);
			return (true);
		}
		free(line);
		dir++;
	}
	return (false);
}

static bool	check_color_lines(char *line, int fd)
{
	if (check_colors(line, "F"))
		return (true);
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

static bool	check_valid_parameters(int fd)
{
	char	*line;

	line = get_next_valid_line(fd);
	if (!line)
		return (true);
	if (check_texture(line, fd))
	{
		err_std(ERR_TEX_FILE);
		return (true);
	}
	line = get_next_valid_line(fd);
	if (!line)
		return (true);
	if (check_color_lines(line, fd))
		return (true);
	return (false);
}

int	checker(char *argv_1)
{
	int		fd;

	if (check_ext(argv_1, ".cub"))
	{
		err_std(ERR_EXTENSION);
		return (-1);
	}
	fd = open(argv_1, O_RDONLY);
	if (fd == -1)
	{
		err_std(ERR_CUB_FILE);
		return (-1);
	}
	if (check_valid_parameters(fd))
	{
		close(fd);
		return (-1);
	}
	return (fd);
}
