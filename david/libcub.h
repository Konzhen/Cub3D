/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:38:40 by dafranco          #+#    #+#             */
/*   Updated: 2023/06/29 15:35:03 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCUB_H
# define LIBCUB_H

# include <../libft.h>
# include <stdbool.h>

int		render(int params, char **argv);
bool	parser(int argc, char **argv);
int		init(int argc, char **argv);
int		scanlines(int pos_player, int pos_map);
int		error(int i);
int		stocker(int i);

#endif
