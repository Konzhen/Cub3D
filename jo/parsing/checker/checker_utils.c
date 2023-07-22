/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:55:05 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/20 23:10:54 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libcub.h"

static char	*skip_empty_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	if (!ft_strncmp(line, "EMPTY", 5))
	{
		free(line);
		return (NULL);
	}
	if (skip_spaces(line, NULL) == -1)
	{
		free(line);
		line = ft_strdup("EMPTY");
		return (line);
	}
	return (line);
}

bool	check_residue(char *line)
{
	while ((*line >= 7 && *line <= 13) || *line == ' ')
		line++;
	if (*line != '\0')
		return (true);
	return (false);
}

bool	check_color_format(char *line, int *i, bool last)
{
	int	color;

	skip_spaces(line, i);
	color = ft_atoi(&line[*i]);
	if (color < 0 || color > 255)
		return (err_std("invalid color value"));
	while (line[*i] >= '0' && line[*i] <= '9')
		(*i)++;
	if (!last)
	{
		skip_spaces(line, i);
		if (line[*i] != ',')
			return (err_std("invalid color value"));
	}
	(*i)++;
	return (false);
}

char	*get_next_valid_line(int fd)
{
	char	*line;

	line = skip_empty_line(fd);
	if (!line)
		return (NULL);
	while (!ft_strncmp(line, "EMPTY", 5))
	{
		free(line);
		line = skip_empty_line(fd);
		if (!line)
			return (NULL);
	}
	return (line);
}