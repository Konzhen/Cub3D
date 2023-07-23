/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:35:10 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/23 15:21:45 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libcub.h"

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
	if (check_texture_line(line, "NO"))
		is_valid = true;
	free(line);
	line = get_next_valid_line(fd);
	if (!line)
		return (true);
	if (check_texture_line(line, "SO"))
		is_valid = true;
	free(line);
	line = get_next_valid_line(fd);
	if (!line)
		return (true);
	if (check_texture_line(line, "WE"))
		is_valid = true;
	free(line);
	line = get_next_valid_line(fd);
	if (!line)
		return (true);
	if (check_texture_line(line, "EA"))
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

char	**checker(char *argv_1)
{
	int		fd;
	char	**tab;

	if (check_ext(argv_1, ".cub"))
		return (NULL);
	fd = open(argv_1, O_RDONLY);
	if (fd == -1)
	{
		err_std("can' t open the file");
		return (NULL);
	}
	if (check_valid_parameters(fd))
	{
		close(fd);
		return (NULL);
	}
	tab = get_tab(get_raw_tab(fd, argv_1));
	if (!tab)
		return (NULL);
	if (check_tab(tab))
		return (NULL);
	return (tab);
}
