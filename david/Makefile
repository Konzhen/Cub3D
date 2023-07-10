# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dafranco <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 14:46:14 by dafranco          #+#    #+#              #
#    Updated: 2023/07/10 11:44:57 by dafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

MY_SOURCES = 	main.c 		\
		map_init.c			\
		map_fill.c			\
		draw.c				\


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
	make clean -C MLX42/build
	rm -f ../libft/*.o

fclean: clean
	rm -f $(NAME)
	make clean -C MLX42/build
	rm -rf ../libft/libft.a

re: fclean all

.PHONY : all bonus clean fclean re
