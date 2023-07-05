/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_check_ext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:44:17 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/05 17:11:21 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_ext(const char *str, const char *ext)
{
	char	*tmp;

	if (!str || !*str || (ft_strlen(str) <= ft_strlen(ext)))
		return (1);
	tmp = ft_strrchr(str, '.');
	if (!tmp)
		return (1);
	if (!ft_strncmp(tmp, ext, ft_strlen(tmp)))
		return (0);
	return (1);
}
