/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:38:40 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/24 08:41:03 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCUB_H
# define LIBCUB_H

//--------------------------------------------------------------------------//
//	-							DEFINES										//
//--------------------------------------------------------------------------//
//
# define WIDTH 256
# define HEIGHT 256
# define PI	3.1415926535
# define STOCK = 0
# define RESET = -1
# define RETURN = 1

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
# include <math.h>

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
}	t_ray;

typedef struct s_player
{
	mlx_image_t			*info;
	char				start;
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				lvl_x;
	double				lvl_y;
	double				angle;
	struct s_ray		*ray;
}	t_player;

typedef struct s_map
{
	char				**tab;
	int					width;
	int					height;
	char				*color_f;
	char				*color_c;
	char				*no;
	char				*so;
	char				*ea;
	char				*we;
}	t_map;

typedef struct s_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	char				*title;
	struct s_map		map;
	struct s_player		*player;
}	t_data;

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
char	**get_raw_tab(int fd, char *argv);
char	**get_tab(char **tab);

//	checker_tab.c
bool	check_tab(char **tab);

// checker_lines_and_columns.c
bool	check_columns(char **tab);
bool	check_lines(char **tab);

//	map_fill.c
void	fill_tab(char **blueprint, char ***tab, size_t y);
char	*fill_line(const char *str);

//	draw.c
void	draw_map(t_data *mlx);
//void	draw_all(void *);

//	main.c
void	draw_player(t_data mlx);
void	ft_player(void *param);

//	draw_ray.c
void	draw_line(void *param);

//	movements.c
void	move_forward(void *param);
void	move_backward(void *param);
void	move_left(void *param);
void	move_right(void *param);

//	stocker.c
char	*stocker_color(int r, int g, int b, int action);

//	game.c
void	init_game(t_data *data);
void	ft_loops(t_data *data);

#endif
