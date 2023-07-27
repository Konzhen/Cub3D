/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hexa_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:24:48 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/27 20:38:46 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static void	ft_cpy(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(str2);
	while (str1[i])
	{
		str2[i + j] = str1[i];
		i++;
	}
	str2[i + j] = '\0';
	return ;
}

static char	*itohex(unsigned int nb)
{
	static char	hex[3];

	if (hex[1] != '\0')
	{
		hex[0] = '\0';
		hex[1] = '\0';
		itohex(nb);
	}
	if (nb / 16 > 0)
		itohex(nb / 16);
	if (nb % 16 >= 10)
		hex[ft_strlen(hex)] = ('A' + (nb % 16) % 10);
	else
		hex[ft_strlen(hex)] = ('0' + (nb % 16));
	hex[2] = '\0';
	return (hex);
}

char	*get_floor_color(int r, int g, int b, bool set)
{
	static char	hexacolor[7];

	if (action == 0)
	{
		ft_cpy(itohex(r), (&hexacolor[0]));
		ft_cpy(itohex(g), (&hexacolor[2]));
		ft_cpy(itohex(b), (&hexacolor[4]));
	}
	else
		return (hexacolor);
	return (NULL);
}

char	*get_ceiling_color(int r, int g, int b, bool set)
{
	static int	hexacolor;

	if (set)
		ft_cpy(itohex(r), (&hexacolor[0]));
	else
		return (hexacolor);
	return (NULL);
}
