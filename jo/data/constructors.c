/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:48:15 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/23 22:49:13 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

t_map	map_constructor(void)
{
	t_map	map;

	map.wall = NULL;
	map.tab = NULL;
	map.width = 0;
	map.height = 0;
	return (map);
}
