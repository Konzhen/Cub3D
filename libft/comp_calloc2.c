/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_calloc2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:08:33 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/24 07:56:51 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc2(size_t nmemb, size_t size)
{
	char	*tab;

	if (!size || !nmemb)
	{
		tab = malloc(0);
		return (tab);
	}
	if ((nmemb * size) / nmemb != size)
		return (NULL);
	tab = malloc(nmemb * size);
	if (!tab)
	{
		err_std("malloc failed");
		return (NULL);
	}
	ft_bzero(tab, (nmemb * size));
	return ((void *)tab);
}
