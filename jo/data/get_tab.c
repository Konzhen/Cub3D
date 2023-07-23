/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:45:18 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/23 19:10:56 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static char	*fd_line_cpy(char *line, int fd2)
{
	char	*tmp;

	tmp = get_next_line(fd2);
	if (!tmp)
		return (NULL);
	while (ft_strncmp(tmp, line, ft_strlen(line)))
	{
		free(tmp);
		tmp = get_next_valid_line(fd2);
		if (!tmp)
			return (NULL);
	}
	return (tmp);
}

static int	get_tab_size(char *line, char *argv_1)
{
	char	*tmp;
	int		size;
	int		fd2;

	fd2 = open(argv_1, O_RDONLY);
	if (fd2 == -1)
		return (-1);
	tmp = fd_line_cpy(line, fd2);
	if (!tmp)
		return (-1);
	size = 0;
	while (tmp != NULL)
	{
		size++;
		free(tmp);
		tmp = get_next_line(fd2);
	}
	free(tmp);
	close(fd2);
	return (size);
}

static int	count_empty_lines(char **raw_tab)
{
	int	i;
	int	y;
	int	size;

	i = 0;
	y = 0;
	size = 0;
	while (raw_tab[y + 1])
		y++;
	while (raw_tab[y])
	{
		while (raw_tab[y][i])
		{
			if (raw_tab[y][i] != ' ' && (raw_tab[y][i] < 7
					|| raw_tab[y][i] > 13))
				return (size);
			i++;
		}
		size++;
		y--;
		i = 0;
	}
	return (0);
}

char	**get_raw_tab(int fd, char *argv_1)
{
	char	*line;
	int		size;
	char	**tab;
	int		i;

	line = get_next_valid_line(fd);
	if (!line)
		return (NULL);
	size = get_tab_size(line, argv_1);
	if (size == -1)
		return (NULL);
	tab = ft_calloc(size + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = line;
		i++;
		line = get_next_line(fd);
	}
	return (tab);
}

char	**get_tab(char **raw_tab)
{
	char	**tab;
	int		size;
	int		i;

	if (!raw_tab)
		return (NULL);
	size = 0;
	while (raw_tab[size])
		size++;
	size -= count_empty_lines(raw_tab);
	if (!size)
		return (NULL);
	tab = ft_calloc(size + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = ft_strdup(raw_tab[i]);
		i++;
	}
	free_tab((void **)raw_tab, 0);
	return (tab);
}
