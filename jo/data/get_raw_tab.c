/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:26:45 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/24 18:13:11 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static int	set_tab_size(char *line, int fd2)
{
	int		size;
	char	*tmp;

	tmp = fd_line_cpy(line, fd2);
	if (!tmp)
	{
		close(fd2);
		return (-1);
	}
	size = 0;
	while (tmp != NULL && *tmp != '\n')
	{
		size++;
		free(tmp);
		tmp = get_next_line(fd2);
	}
	free(tmp);
	close(fd2);
	return (size);
}

static int	get_tab_size(char *line, char *argv_1)
{
	int		size;
	int		fd2;

	fd2 = open(argv_1, O_RDONLY);
	if (fd2 == -1)
	{
		err_std(ERR_CUB_FILE);
		return (-1);
	}
	size = set_tab_size(line, fd2);
	if (size == -1)
		free(line);
	return (size);
}

static char	**fill_raw_tab(char *line, int size, int fd)
{
	char	**raw_tab;
	int		i;

	raw_tab = calloc2(size + 1, sizeof(char *));
	if (!raw_tab)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		raw_tab[i] = line;
		i++;
		line = get_next_line(fd);
	}
	free(line);
	return (raw_tab);
}

char	**get_raw_tab(int fd, char *argv_1)
{
	char	*line;
	int		size;
	char	**raw_tab;

	line = get_next_valid_line(fd);
	if (!line)
		return (NULL);
	size = get_tab_size(line, argv_1);
	if (size == -1)
		return (NULL);
	raw_tab = fill_raw_tab(line, size, fd);
	if (!raw_tab)
		return (NULL);
	return (raw_tab);
}
