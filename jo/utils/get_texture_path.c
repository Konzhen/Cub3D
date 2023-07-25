/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:58:45 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/25 19:59:36 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static size_t	ft_strlcpy_texture(char *dest, const char *src
	, int *i, size_t size)
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
