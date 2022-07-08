# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 17:04:39 by mikabuto          #+#    #+#              #
#    Updated: 2022/07/08 17:10:43 by mikabuto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c color.c init.c lib_ft.c formulas.c hook.c
OBJ = $(SRC:.c=.o)

MINILIBX = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

CC = cc
CFLAGS = -Wall -Werror -Wextra

HEADER = fractol.h mlx_keycode.h

all: $(NAME)

run: $(NAME)
	leaks --atExit -- ./$(NAME) Mandelbrot

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MINILIBX) -o $(NAME)

%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re