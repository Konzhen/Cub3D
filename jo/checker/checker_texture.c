/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:55:27 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/24 10:57:58 by jbutte           ###   ########.fr       */
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

size_t	ft_strlcpy_texture(char *dest, const char *src, int *i, size_t size)
{
	size_t	j;
	size_t	srcsize;

	if (*src == '\0')
		return (0);
	srcsize = ft_strlen(src);
	if (!size)
		return (srcsize);
	j = 0;
	while (src[*i] && j < size - 1)
	{
		dest[j] = src[*i];
		j++;
		(*i)++;
	}
	dest[j] = '\0';
	return (srcsize);
}

char	*get_texture_path(char *line, int *i)
{
	size_t	size;
	size_t	j;
	char	*tex_path;

	size = 0;
	j = *i;
	while (((line[j] < 7 || line[j] > 13) && line[j] != ' ') && line[j])
	{
		j++;
		size++;
	}
	tex_path = calloc2(size + 1, sizeof(char));
	if (!tex_path)
		return (NULL);
	ft_strlcpy_texture(tex_path, line, i, size + 1);
	if (check_ext(tex_path, ".jpg") || check_residue(&line[*i]))
	{
		free(tex_path);
		return (NULL);
	}
	return (tex_path);
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
