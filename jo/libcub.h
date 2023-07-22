/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:38:40 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/22 18:44:10 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCUB_H
# define LIBCUB_H

//--------------------------------------------------------------------------//
//	-							DEFINES										//
//--------------------------------------------------------------------------//

//--------------------------------------------------------------------------//
//	- 							INCLUDES									//
//--------------------------------------------------------------------------//

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
//# include "MLX42/include/MLX42/MLX42_Int.h"
# include <stdbool.h>
# include <stdio.h>

//--------------------------------------------------------------------------//
//	- 							VARIABLES									//
//--------------------------------------------------------------------------//

//--------------------------------------------------------------------------//
//	-							STRUCTURES									//
//--------------------------------------------------------------------------//

//--------------------------------------------------------------------------//
//	-							FUNCTIONS									//
//--------------------------------------------------------------------------//

int		render(int params, char **argv);
bool	parser(int argc, char **argv);
int		init(int argc, char **argv);
int		scanlines(int pos_player, int pos_map);
int		error(int i);
int		stocker(int i);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~./parsing/checker/

//	checker.c
char	**checker(char *argv_1);

//	checker_utils.c
bool	check_residue(char *line);
bool	check_color_format(char *line, int *i, bool last);
char	*get_next_valid_line(int fd);

//	checker_texture.c
bool	check_texture_line(char *line, char *tex);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~./parsing/checker/chercker_tab/

//	checker_get_tab.c
char	**get_raw_tab(int fd, char *argv_1);
char	**get_tab(char **tab);

//	checker_tab.c
bool	check_tab(char **tab);

// checker_lines_and_columns.c
bool	check_columns(char **tab);
bool	check_lines(char **tab);

int		main(int argc, char **argv);

#endif
