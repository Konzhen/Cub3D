/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 05:02:45 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/24 05:13:16 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

void	free_map(t_map *map)
{
	free_tab((void **)map->tab, 0);
	if (color_f)
		free(color_f);
	if (color_c)
		free(color_c);
	if (no)
		free(no);
	if (so)
		free(so);
	if (we)
		free(we);
	if (ea)
		free(ea);
}