/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:46:54 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/24 04:23:04 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static int	is_right_char(char c)
{
	if (c != '1' && c != '0' && c != 'N' && c != '\n' && c != 'S' && c != 'E'
		&& c != 'W' && c != ' ')
		return (0);
	else if (c == 'S' || c == 'N' || c == 'E' || c == 'W')
		return (2);
	else
		return (1);
}

static bool	check_around_path(char **tab, int x, int y)
{
	if (tab[y - 1][x] == ' ' || tab[y - 1][x] == '\n' || !tab[y - 1][x])
		return (true);
	if (tab[y + 1][x] == ' ' || tab[y + 1][x] == '\n' || !tab[y + 1][x])
		return (true);
	if (tab[y][x + 1] == ' ' || tab[y][x + 1] == '\n' || !tab[y][x + 1])
		return (true);
	if (tab[y][x - 1] == ' ' || tab[y][x - 1] == '\n' || !tab[y][x - 1])
		return (true);
	if (tab[y - 1][x - 1] == ' ' || tab[y - 1][x - 1] == '\n' || !tab[y - 1][x
		- 1])
		return (true);
	if (tab[y + 1][x + 1] == ' ' || tab[y + 1][x + 1] == '\n' || !tab[y + 1][x
		+ 1])
		return (true);
	if (tab[y - 1][x + 1] == ' ' || tab[y - 1][x + 1] == '\n' || !tab[y - 1][x
		+ 1])
		return (true);
	if (tab[y + 1][x - 1] == ' ' || tab[y + 1][x - 1] == '\n' || !tab[y + 1][x
		- 1])
		return (true);
	return (false);
}

static bool	check_valid_char(char **tab)
{
	int	x;
	int	y;
	int	value;
	int	n_of_dir;

	x = 0;
	y = 0;
	n_of_dir = 0;
	while (tab[y])
	{
		while (tab[y][x])
		{
			value = is_right_char(tab[y][x]);
			if (!value)
				return (true);
			else if (value == 2)
				n_of_dir++;
			x++;
		}
		x = 0;
		y++;
	}
	if (n_of_dir != 1)
		return (true);
	return (false);
}

static bool	check_valid_closure(char **tab)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tab[y])
	{
		while (tab[y][x])
		{
			if (tab[y][x] == '0' || tab[y][x] == 'W' || tab[y][x] == 'S'
				|| tab[y][x] == 'E' || tab[y][x] == 'N')
			{
				if (check_around_path(tab, x, y))
					return (true);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (false);
}

bool	check_tab(char **tab)
{
	bool	valid;

	valid = false;
	if (check_valid_char(tab))
		valid = true;
	if (check_lines(tab) || check_columns(tab))
		valid = true;
	if (check_valid_closure(tab))
		valid = true;
	if (valid)
	{
		free_tab((void **)tab, 0);
		tab = NULL;
	}
	return (valid);
}
