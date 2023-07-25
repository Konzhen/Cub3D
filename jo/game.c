/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:57:19 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/23 23:05:44 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

void	init_game(t_data data)
{
	data->mlx_ptr = mlx_init(WIDTH, HEIGHT, "A-MAZE-ING", true);
}

void	ft_loops(t_data data)
{
	mlx_loop_hook(data->mlx_ptr, ft_player, data->mlx_ptr);
	mlx_loop_hook(data->mlx_ptr, move_forward, data->mlx_ptr);
}
