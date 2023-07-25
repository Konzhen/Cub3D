/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_valid_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:46:48 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/25 19:47:59 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static char	*skip_empty_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	if (!ft_strncmp(line, "EMPTY", 5))
	{
		free(line);
		err_std(EMPTY_BAIT);
		return (NULL);
	}
	if (skip_spaces(line, NULL) == -1)
	{
		free(line);
		line = ft_strdup("EMPTY");
		if (!line)
		{
			err_std(MALLOC);
			return (NULL);
		}
	}
	return (line);
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
