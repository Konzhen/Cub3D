/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tab_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:59:35 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/24 03:07:22 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

char	*fd_line_cpy(char *line, int fd2)
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

int	count_empty_lines(char **raw_tab)
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