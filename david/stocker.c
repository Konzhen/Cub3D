/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:24:48 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/27 21:02:05 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

uint32_t	get_color_c(int r, int g, int b, int action)
{
	static uint32_t	hexacolor;

	if (action == 0)
		hexacolor = ((1 << 24) + (r << 16) + (g << 8) + b);
	else if (action > 0)
		return (hexacolor);
	return (0);
}

uint32_t	get_color_f(int r, int g, int b, int action)
{
	static uint32_t	hexacolor;

	if (action == 0)
		hexacolor = ((1 << 24) + (r << 16) + (g << 8) + b);
	else if (action > 0)
		return (hexacolor);
	return (0);
}
