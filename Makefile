# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 17:04:39 by mikabuto          #+#    #+#              #
#    Updated: 2022/07/06 19:27:09 by mikabuto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c color.c init.c mlx_func.c
OBJ = $(SRC:.c=.o)

LIBFT = libft.a
LIBFTFLAG = -Llibft -lft

MINILIBX = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

CC = cc
CFLAGS = -Wall -Werror -Wextra

HEADER = fractol.h

all: $(LIBFT) $(NAME)

run: $(NAME)
	./$(NAME) Mandelbrot

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MINILIBX) $(LIBFTFLAG) -o $(NAME)

%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(LIBFT):
	@make -C libft

clean:
	rm -f $(OBJ)
	@make -C libft clean
	
fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re