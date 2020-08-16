# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gloggins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 16:32:11 by gloggins          #+#    #+#              #
#    Updated: 2020/03/11 16:32:12 by gloggins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

# Colors

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = gloggins.filler

LIBFT = libft/libft.a

INCLUDES = -I./libft/includes/ -I./includes/

SRC = src/main.c \
	  src/get_coordinates.c \
	  src/heat_distance.c \
	  src/map_fill.c \
	  src/memory_free.c \
	  src/piece_fill.c \
	  src/sort_coord.c 

OBJ = $(SRCS:.c=.o)

all : $(NAME)

allclean : all clean

$(NAME) : $(LIBFT) $(SRC) $(LIBFT)
	@$(CC) $(FLAGS) $(INCLUDES) $(SRC) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Player for the filler game is ready to use$(RESET)"

$(LIBFT) :
	@make -C libft

clean :
	@make clean -C libft
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)
	@echo "$(YELLOW)Player removed$(RESET)"

re : fclean all