/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:41:32 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/23 22:05:55 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static t_map	map_constructor(void)
{
	t_map	map;

	map.wall = NULL;
	map.tab = NULL;
	map.width = 0;
	map.height = 0;
	return (map);
}

static bool	**get_wall(char **tab)
{
	bool	**wall;

	wall = 
}

t_map	get_map(char *argv_1)
{
	t_map	map;
	char	**tab;

	map = map_constructor();
	tab = checker(argv_1);
	if (!tab)
		return (map);
	map.wall = get_wall(tab);
}