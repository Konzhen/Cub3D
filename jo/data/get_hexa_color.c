/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hexa_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:24:48 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/28 18:19:35 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

uint32_t	get_color_c(int r, int g, int b, int action)
{
	static uint32_t	hexacolor;

	if (action == 0)
		hexacolor = r << 24 | g << 16 | b << 8 | 255;
	else if (action > 0)
		return (hexacolor);
	return (0);
}

uint32_t	get_color_f(int r, int g, int b, int action)
{
	static uint32_t	hexacolor;

	if (action == 0)
		hexacolor = r << 24 | g << 16 | b << 8 | 255;
	else if (action > 0)
		return (hexacolor);
	return (0);
}
