/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:38:40 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/24 05:42:12 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCUB_H
# define LIBCUB_H

//--------------------------------------------------------------------------//
//	-							DEFINES										//
//--------------------------------------------------------------------------//
# define WIDTH 256
# define HEIGHT 256
# define PI 3.1415926535
//--------------------------------------------------------------------------//
//	- 							INCLUDES									//
//--------------------------------------------------------------------------//

# include "../libft/libft.h"
# include "MLX42/include/MLX42/MLX42_Int.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>

//--------------------------------------------------------------------------//
//	- 							VARIABLES									//
//--------------------------------------------------------------------------//

//--------------------------------------------------------------------------//
//	-							STRUCTURES									//
//--------------------------------------------------------------------------//

typedef struct s_ray
{
	double				size;
	double				dir_x;
	double				dir_y;
	double				side_x;
	double				side_y;
}						t_ray;

typedef struct s_player
{
	char				start;
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				lvl_x;
	double				lvl_y;
	struct s_ray		*ray;
}						t_player;

typedef struct s_map
{
	char				**tab;
	int					width;
	int					height;
	char				*color_f;
	char				*color_c;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
}						t_map;

typedef struct s_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	char				*title;
	struct s_map		map;
	struct s_player		*player;
}						t_data;

//--------------------------------------------------------------------------//
//	-							FUNCTIONS									//
//--------------------------------------------------------------------------//

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~./

//	map_fill.c
void					fill_tab(char **blueprint, char ***tab, size_t y);
char					*fill_line(const char *str);

//	draw.c
void					draw_map(t_data mlx);

//	main.c
void					draw_player(t_data *mlx);

//	draw_ray.c
void					draw_line(void *param);

int						render(int params, char **argv);
bool					parser(int argc, char **argv);
int						init(int argc, char **argv);
int						scanlines(int pos_player, int pos_map);
int						error(int i);
int						stocker(int i);

//	movements.c
void					move_forward(void *param);

//	stocker.c
char					*stocker_color(int r, int g, int b, int action);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~./checker/

//	checker.c
int						checker(char *argv_1);

//	checker_utils.c
bool					check_residue(char *line);
bool					check_color_format(char *line, int *i, bool last);
char					*get_next_valid_line(int fd);

//	checker_texture.c
char					*get_texture_path(char *line, int *i);
bool					check_texture_line(char *line, char *tex, int option);

//	checker_tab.c
bool					check_tab(char **tab);

// checker_lines_and_columns.c
bool					check_columns(char **tab);
bool					check_lines(char **tab);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~./data/

//	construtors.c
t_map					map_constructor(void);

//	get_data.c
t_data					get_data(int fd);

//	get_map.c

//	get_map_utils.c
bool					fill_texture(t_map *map, int fd, char *line, int tex_n);
bool					set_colors(t_map *map, int fd);
void					set_width_and_heigth(t_map *map);

//	get_tab.c
char					**get_raw_tab(int fd, char *argv_1);
char					**get_tab(char **tab);

//	get_tab_utils.c
char					*fd_line_cpy(char *line, int fd2);
int						count_empty_lines(char **raw_tab);

//	storage_texture.c
char					*manage_stock_texture(char *tex_path, int option);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~./free/

//	free_map.c
void					free_map(t_map *map);

#endif
