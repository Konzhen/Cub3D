/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_skip_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:20:52 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/05 17:24:11 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	skip_spaces(const char *line, int *i)
{
	int	j;

	j = 0;
	if (!i)
		i = &j;
	if (!line || !line[*i])
		return (0);
	while (line[*i] == ' ')
		(*i)++;
	if (!line[*i])
		return (0);
	return (*i);
}
