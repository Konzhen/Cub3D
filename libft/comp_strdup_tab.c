/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_strdup_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:33:44 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/24 10:19:29 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**strdup_tab(char **tab)
{
	char	**cpy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
		i++;
	cpy = calloc2(i + 1, sizeof(char *));
	if (!cpy)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		while (tab[i][j])
			j++;
		cpy[i] = ft_strdup(tab[i]);
		j = 0;
		i++;
	}
	return (cpy);
}
