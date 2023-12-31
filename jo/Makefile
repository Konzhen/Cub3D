# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 14:46:14 by dafranco          #+#    #+#              #
#    Updated: 2023/07/28 17:59:18 by jbutte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

MY_SOURCES = 	main.c											\
				draw.c											\
				free_structs.c									\
				utils/get_next_valid_line.c						\
				utils/get_texture_path.c						\
				checker/checker.c								\
				checker/checker_utils.c							\
				checker/checker_texture.c						\
				checker/checker_tab.c							\
				checker/checker_lines_and_columns.c				\
				data/constructors.c								\
				data/get_data.c									\
				data/get_hexa_color.c							\
				data/get_map_utils.c							\
				data/get_map.c									\
				data/get_player.c								\
				data/get_raw_tab.c								\
				data/get_tab.c									\

MY_OBJECTS = $(MY_SOURCES:%.c=%.o)

CC = clang

CFLAGS = -Wall -Werror -Wextra -g

all : $(NAME)

$(NAME): $(MY_OBJECTS)
	make -C ../libft/
	cmake MLX42 -B MLX42/build && make -C MLX42/build -j4
	$(CC) $(CFLAGS) -L ../libft -I ../libft $(MY_OBJECTS) -l:../libft/libft.a -I/usr/include MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -o $(NAME)

clean:
	rm -f $(MY_OBJECTS)
	rm -f checker/$(MY_OBJECTS)
	rm -f checker_tab/$(MY_OBJECTS)
	rm -f data/$(MY_OBJECTS)
	make clean -C MLX42/build
	rm -f ../libft/*.o

fclean: clean
	rm -f $(NAME)
	make clean -C MLX42/build
	rm -rf ../libft/libft.a

re: fclean all

.PHONY : all bonus clean fclean re
