/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:38:40 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/08 20:37:32 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCUB_H
# define LIBCUB_H

//--------------------------------------------------------------------------//
//	-							DEFINES										//
//--------------------------------------------------------------------------//
# define WIDTH 256
# define HEIGHT 256
//--------------------------------------------------------------------------//
//	- 							INCLUDES									//
//--------------------------------------------------------------------------//

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42_Int.h"
# include <stdio.h>
# include <stdbool.h>

//--------------------------------------------------------------------------//
//	- 							VARIABLES									//
//--------------------------------------------------------------------------//

//--------------------------------------------------------------------------//
//	-							STRUCTURES									//
//--------------------------------------------------------------------------//
typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	char	*title;
	int		x;
	int		y;
	int		width;
	int		height;
}t_vars;
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

//	checker_.c
bool	checker(char *argv_1);

//	checker_utils.c
bool    check_color_format(char *line, int *i);
bool    check_texture_line(char *line, char *tex, int fd);
char	*skip_empty_line(int fd);
char    *get_next_valid_line(int fd);

//	map_fill.c
void	fill_tab(char **blueprint, char ***tab, size_t y);
char	*fill_line(const char *str);

#endif
