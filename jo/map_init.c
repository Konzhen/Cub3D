/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:14:09 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/07 17:44:27 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libcub.h"

/*static ssize_t get_mapsize_y(const char **blueprint)
{
	ssize_t	i;

	i = 0;
	return (i);
}

static ssize_t get_mapsize_x(const char *blueprint)
{
	ssize_t	i;

	i = 0;
	while (blueprint[i] && blueprint[i] != '\n')
		i++;
	return (i);
}

static char	**map_len(const char **blueprint)
{
	static ssize_t	x;
	static ssize_t	y;
	int				i;
	char			**map;

	i = 0;
	while (*blueprint)
	{
		if (get_mapsize_y(*blueprint[i]) > x)
			x = get_mapsize(*blueprint[i]);
		i++;
	}
}
*/
