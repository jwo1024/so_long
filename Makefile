# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:27:03 by jiwolee           #+#    #+#              #
#    Updated: 2022/07/28 09:40:08 by jiwolee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= cc
CFLAGS		= -Wall -Werror -Wextra

MLX_FLAGS	= -lmlx -framework OpenGL -framework AppKit
MLX_DIR		= ./mlx

HEADER		= ./includes
INCLUDES	= -I$(HEADER) -I$(MLX_DIR)

SRCS_1		= ./mandatory/so_long.c\
			  ./mandatory/check_position.c\
			  ./mandatory/exit.c\
			  ./mandatory/read_map.c\
			  ./mandatory/draw_map.c\
			  ./mandatory/utils.c
			 
SRCS_2		= ./gnl_for_solong/get_next_line.c\
			  ./gnl_for_solong/get_next_line_utils.c

SRCS		= $(SRCS_1) $(SRCS_2)

OBJS		= $(SRCS:.c=.o)

%.o : %.c
		${CC} ${CFLAGS} $(INCLUDES) -c -o $@ $^

$(NAME) : $(OBJS)
		make -C $(MLX_DIR)
		$(CC) $(CFLAG) $(INCLUDES) -o $@ $^ -L $(MLX_DIR) $(MLX_FLAGS)

all : $(NAME)

clean :
		rm -f $(OBJS)
		make $@ -C $(MLX_DIR)

fclean : clean
		rm -f $(NAME)

re : clean all

PHONY : all clean fclean re