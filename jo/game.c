/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:57:19 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/27 13:34:27 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	init_game(t_data *data)
{
	data->mlx_ptr = mlx_init(WIDTH, HEIGHT, "A-MAZE-ING", true);
}

void	ft_loops(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, move_forward, data);
	mlx_loop_hook(data->mlx_ptr, move_backward, data);
	mlx_loop_hook(data->mlx_ptr, move_left, data);
	mlx_loop_hook(data->mlx_ptr, move_right, data);
	mlx_loop(data->mlx_ptr);
}
