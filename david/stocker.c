/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:24:48 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/24 06:54:10 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

static char	*itohex(unsigned int nb);
static void	ft_cpy(char *str1, char *str2);

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

char	*stocker_color(int r, int g, int b, int action)
{
	static char	hexacolor[6];

	if (action == 0)
	{
		ft_cpy(itohex(r), (&hexacolor[0]));
		ft_cpy(itohex(g), (&hexacolor[2]));
		ft_cpy(itohex(b), (&hexacolor[4]));
	}
	else if (action == -1)
		hexacolor[0] = '\0';
	else if (action > 0)
		return (hexacolor);
	return (NULL);
}

static char	*itohex(unsigned int nb)
{
	static char	hex[2];

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
	return (hex);
}
