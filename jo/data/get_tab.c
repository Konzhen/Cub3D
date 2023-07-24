/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:45:18 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/24 17:57:50 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static bool	get_new_tab(char **raw_tab, int size)
{
	char	**tab;
	int		i;

	tab = calloc2(size + 1, sizeof(char *));
	if (!tab)
		return (true);
	i = 0;
	while (i < size)
	{
		tab[i] = ft_strdup(raw_tab[i]);
		if (!tab[i])
		{
			free_tab((void **)tab, 0);
			return (true);
		}
		i++;
	}
	return (false);
}

static int	get_new_size(char **raw_tab)
{
	int	size;

	size = 0;
	while (raw_tab[size] && raw_tab[size][0] != '\n')
		size++;
	size -= count_empty_lines(raw_tab);
	if (!size)
		return (-1);
}

char	**get_tab(char **raw_tab)
{
	char	**tab;
	int		size;

	if (!raw_tab)
		return (NULL);
	size = get_new_size(raw_tab);
	if (size == -1)
	{
		free_tab((void **)raw_tab, 0);
		return (NULL);
	}
	tab = get_new_tab(raw_tab, size);
	if (!tab)
	{
		free_tab((void **)raw_tab, 0);
		return (NULL);
	}
	free_tab((void **)raw_tab, 0);
	return (tab);
}
