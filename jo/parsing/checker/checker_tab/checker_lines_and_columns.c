/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_lines_and_columns.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:38:16 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/22 18:45:46 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libcub.h"

bool	check_columns(char **tab)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tab[y])
	{
		if (tab[y][0] == '0')
			return (true);
		while (tab[y][x + 1] != '\n' && tab[y][x + 1])
			x++;
		if (tab[y][x] == '0')
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
		if (tab[0][x] == '0')
			return (true);
		x++;
	}
	x = 0;
	while (tab[y + 1])
		y++;
	while (tab[y][x])
	{
		if (tab[y][x] == '0')
			return (true);
		x++;
	}
	return (false);
}