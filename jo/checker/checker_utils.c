/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:55:05 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/25 19:49:13 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

bool	check_color_format(char *line, int *i, bool last)
{
	int	color;

	skip_spaces(line, i);
	color = ft_atoi(&line[*i]);
	if (color < 0 || color > 255)
	{
		err_std(ERR_COLOR_VALUE);
		return (true);
	}
	while (line[*i] >= '0' && line[*i] <= '9')
		(*i)++;
	if (!last)
	{
		skip_spaces(line, i);
		if (line[*i] != ',')
		{
			err_std(ERR_COLOR_VALUE);
			return (true);
		}
	}
	(*i)++;
	return (false);
}

bool	check_residue(char *line)
{
	while ((*line >= 7 && *line <= 13) || *line == ' ')
		line++;
	if (*line != '\0')
		return (true);
	return (false);
}
