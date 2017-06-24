# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcuer <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/04 15:45:58 by tcuer             #+#    #+#              #
#    Updated: 2017/06/24 18:34:43 by tcuer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MKEX = cc -o

SRC = main.c ft_error.c ft_print.c ft_mandelbrot.c ft_julia.c ft_mandelbar.c \
	  ft_hook.c

FLAGS = -Wall -Wextra -Werror

OBJECT = $(SRC:.c=.o)

COMP = cc -c

NAME = fractol

INCLUDESLIB = ./libft/includes/

all : $(NAME)

$(NAME) : $(OBJECT)
	@echo "Compilation Fract_ol"
	@$(MKEX) $(NAME) $(OBJECT)  ./minilibx_macos/libmlx.a -framework OpenGL -framework AppKit -L libft/ -lft
	@echo "Done"

$(OBJECT) :
	@make -C libft/
	@$(COMP) $(SRC) $(FLAGS) -I./ -I /usr/X11/include/ -I $(INCLUDESLIB)

clean :
	@make clean -C libft/
	@/bin/rm -f $(OBJECT)
	@echo "Object deleted"

fclean : clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)
	@echo "Folder cleanup successful"

re : fclean all
