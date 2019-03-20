# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 16:06:30 by aruiz-ba          #+#    #+#              #
#    Updated: 2019/03/20 17:00:09 by aruiz-ba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

# directories
SRC_DIR	:= ./src
INC_DIR	:= ./includes
OBJ_DIR	:= ./obj
LIB_DIR	:= ./lib

SRC = ./src/main.c \
		./src/ft_valid_input.c \
		./src/ft_parse.c \
		./src/ft_mvtop.c \
		./src/ft_print.c \
		./src/ft_solve.c \
		./src/ft_putrem.c \
		./src/ft_checkplc.c \
		./src/ft_set.c \
		./src/ft_mino.c

$(NAME): $(SRC)
	@make -C libft/
	@clang -o $(NAME) -I $(INC_DIR) $(SRC) libft/libft.a
	@echo "_________________"
	@echo "                 "
	@echo "    SUCCESS!     "
	@echo "     fillit      "
	@echo "    was created  "
	@echo "_________________"


all: $(NAME)

clean:
	@make -C libft/ clean

fclean:
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all $(NAME)

# flag segmentation faults: -fsanitize=address
