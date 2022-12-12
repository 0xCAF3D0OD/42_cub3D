# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 15:03:47 by amuhleth          #+#    #+#              #
#    Updated: 2022/11/23 15:56:16 by amuhleth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------------------------------------------------------

NAME		= cub3d
CC			= gcc
CFLAGS 		= -Wall -Wextra -Werror

# LFTDIR 		= ./libft
# LIBFT		= $(LFTDIR)/libft.a

INCL		= -I. -I./mlx -I./libft
LIB			= -L./libft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit

SRCS_PATH 	= ./srcs/
SRCS 		= $(addprefix $(SRCS_PATH), $(FILES))
OBJS		= $(SRCS:.c=.o)
FILES		+=	main.c				\
				draw_minimap.c		\
				draw_column.c		\
				render_column.c		\
				exit.c				\
				keyboard.c			\
				move.c				\
				ray.c				\
				ray2.c				\
				render_frame.c		\
				error.c				\
				utils.c				\
				textures.c			\

FILES		+=  $(addprefix parsing/,	\
				0_parser_main.c			\
 			  	M_parser_map.c			\
			  	C_parser_color.c		\
			  	S_parser_sprite.c		\
 			  	A_stock_arguments.c		\
 			  	M_stock_map.c			\
 			  	A_height_calculator.c	\
 			  	A_tools_fct.c			\
 			  	A_tools_fct2.c			\
 			  	A_error_manager.c		\
 			  	C_checker_color.c		\
 			  	S_checker_sprite.c		\
 			  	A_str_search_keyWords.c)

# =============================================================================

all :	$(NAME)

%.o :	%.c
	$(CC) $(CFLAGS) $(INCL) -c $< -o $@

$(NAME) :	libft.a libmlx.a $(OBJS)
	$(CC) $(CFLAGS) $(INCL) $(LIB) $(OBJS) -o $(NAME)

libft.a :
	make -C ./libft

libmlx.a :
	make -C ./mlx

sclean :
	rm -rf $(OBJS)

clean : sclean
	make fclean -C ./libft
	make clean -C ./mlx

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
