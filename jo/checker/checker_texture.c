/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:55:27 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/25 19:59:27 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static int	reach_texture_path(char *line, int dir)
{
	int		i;
	char	*tex;

	i = 0;
	if (dir == 0)
		tex = "NO";
	if (dir == 1)
		tex = "SO";
	if (dir == 2)
		tex = "WE";
	if (dir == 3)
		tex = "EA";
	skip_spaces(line, &i);
	if (ft_strncmp(&line[i], tex, 2))
		return (-1);
	i += 2;
	if (!skip_spaces(line, &i))
		return (-1);
	return (i);
}

bool	check_texture_line(char *line, int dir)
{
	char	*tex_path;
	int		tmp;
	int		i;

	i = reach_texture_path(line, dir);
	if (i == -1)
		return (true);
	tex_path = get_texture_path(line, &i);
	if (!tex_path)
		return (true);
	tmp = open(tex_path, O_RDONLY);
	if (tmp == -1)
	{
		free(tex_path);
		return (true);
	}
	free(tex_path);
	close(tmp);
	return (false);
}
