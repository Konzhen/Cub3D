/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_lines_and_columns.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:38:16 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/24 13:02:51 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

bool	check_columns(char **tab)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tab[y])
	{
		if (tab[y][0] == '0' || tab[y][0] == 'N' || tab[y][0] == 'E'
			|| tab[y][0] == 'S' || tab[y][0] == 'W')
			return (true);
		while (tab[y][x] && tab[y][x + 1] && tab[y][x + 1] != '\n')
			x++;
		if (tab[y][x] == '0' || tab[y][x] == 'N' || tab[y][x] == 'E'
			|| tab[y][x] == 'S' || tab[y][x] == 'W')
			return (true);
		x = 1;
		y++;
	}
	return (false);
}

bool	check_lines(char **tab)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tab[0][x])
	{
		if (tab[0][x] == '0' || tab[0][x] == 'N' || tab[0][x] == 'E'
			|| tab[0][x] == 'S' || tab[0][x] == 'W')
			return (true);
		x++;
	}
	x = 0;
	while (tab[y + 1])
		y++;
	while (tab[y][x])
	{
		if (tab[y][x] == '0' || tab[y][x] == 'N' || tab[y][x] == 'E'
			|| tab[y][x] == 'S' || tab[y][x] == 'W')
			return (true);
		x++;
	}
	return (false);
}