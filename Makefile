#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 11:59:25 by tbratsla          #+#    #+#              #
#    Updated: 2019/03/11 11:59:26 by tbratsla         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= fdf

SRC	= 	src/draw_map.c \
		src/main.c \
		src/read_map.c \
		src/turn.c \
		src/move_scale.c \
		src/help_to_norm.c \
		src/draw_line.c \
		src/keys.c 

OBJ     = $(SRC:.c=.o)
LIBFT   = Libft/
HDR  = inc/fdf.h 
CC      = /usr/bin/gcc
CFLAGS  = -Wall -Wextra -Werror
FMLX    = -framework OpenGL -framework AppKit -lmlx
DEL      = /bin/rm -f

all:        $(NAME)

$(NAME):    $(OBJ) $(LIBFT)
	make -o3 -C $(LIBFT)	
	$(CC) -o3 $(CFLAGS) -o $(NAME) $(OBJ) -I $(HDR) -L $(LIBFT) -lft $(FMLX)

%.o : %.c $(HDR) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ -c $< -I .

clean:
	make fclean -C $(LIBFT)
	$(DEL) $(OBJ)

fclean:     clean
	make -C $(LIBFT) fclean
	$(DEL) $(NAME)


re:     fclean all

.PHONY:     re all clean fclean

	