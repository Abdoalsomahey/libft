# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amhussei <amhussei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 01:28:21 by amhussei          #+#    #+#              #
#    Updated: 2023/08/30 01:28:21 by amhussei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
GNL = gnl/get_next_line.c gnl/get_next_line_utils.c
SRC = so_long.c parsing.c check_map.c create_map.c valid_path.c start_game.c $(GNL)
OBJ = ${SRC:.c=.o} 
CC = cc
CFLAG = -Wall -Wextra -Werror


all : ${NAME}

${NAME} : ${OBJ}
	make -C ./libft
	make -C ./mlx
	${CC} ${CFLAG} ${OBJ} -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -Llibft -lft  -o ${NAME}

clean :
	make -C ./libft clean
	make -C ./mlx clean
	rm -f ${OBJ}

fclean : clean
	make -C ./libft fclean
	rm -f ${NAME}

re : fclean all