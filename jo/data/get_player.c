/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:24:01 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/25 20:52:46 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static void	set_player_pos(t_player *player, char **tab)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (tab[y])
	{
		while (tab[y][x])
		{
			if (tab[y][x] == 'N' || tab[y][x] == 'S'
			|| tab[y][x] == 'E' || tab[y][x] == 'W')
			{
				player->pos_x = (double)x;
				player->pos_y = (double)y;
				player->start = tab[y][x];
			}
			x++;
		}
		y++;
		x = 0;
	}
}

t_player	*get_player(char **tab)
{
	t_player	*player;

	player = player_constructor();
	if (!player)
		return (NULL);
	set_player_pos(player, tab);
	return (player);
}
