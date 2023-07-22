/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:55:27 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/22 18:47:02 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libcub.h"

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

static char	*get_texture_path(char *line, int *i)
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
	tex_path = ft_calloc(size + 1, sizeof(char));
	if (!tex_path)
		return (NULL);
	j = 0;
	ft_strlcpy_texture(tex_path, line, i, size + 1);
	if (check_residue(&line[*i]))
		return (NULL);
	return (tex_path);
}

bool	check_texture_line(char *line, char *tex)
{
	char	*tex_path;
	int		tmp;
	int		i;

	i = 0;
	skip_spaces(line, &i);
	if (ft_strncmp(&line[i], tex, 3))
		return (true);
	i += 2;
	skip_spaces(line, &i);
	tex_path = get_texture_path(line, &i);
	if (!tex_path || check_ext(tex_path, ".jpg"))
	{
		if (tex_path)
			free(tex_path);
		return (true);
	}
	tmp = open(tex_path, O_RDONLY);
	free(tex_path);
	if (tmp == -1)
		return (err_std("failed to open file"));
	close(tmp);
	return (false);
}