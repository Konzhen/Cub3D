/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:20:33 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/11 00:06:47 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

char	*fill_line(const char *str)
{
	int		len;
	int		j;
	int		i;
	int		k;
	char	*newstr;

	len = ft_strlen(str);
	newstr = (char *)malloc((9 * len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	k = 0;
	j = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < 9)
		{
			newstr[k++] = str[i];
			j++;
		}
		i++;
	}
	newstr[k] = '\0';
	return (newstr);
}

void	fill_tab(char **blueprint, char ***tab, size_t y)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	(*tab) = (char **)malloc((y * 9) * sizeof(char **) + 1);
	if (!tab)
		return ;
	while (j < (int)y)
	{
		while (i < 9)
		{
			(*tab)[k] = fill_line(blueprint[j]);
			i++;
			k++;
		}
		i = 0;
		j++;
	}
}
