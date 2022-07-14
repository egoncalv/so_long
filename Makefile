# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/28 01:09:23 by egoncalv          #+#    #+#              #
#    Updated: 2022/06/18 23:26:30 by erickbarros      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

INCLUDE = -I/usr/include -Imlx_linux -O3

MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

NAME = so_long

SRC =	src/main.c \
		src/utils.c \
		src/parse_maps.c \
		src/exit.c \
		src/init_mlx.c \
		src/draw_map.c \
		src/move_player.c \
		src/hooks.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

LIBS_OBJ =	ft_printf/src/*.o \
			ft_printf/libft/*.o \
			

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJ) mlx
	@echo $(CURSIVE)$(GRAY) "     - Making ft_printf..." $(NONE)
	@$(MAKE) -C ft_printf
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)" $(NONE)
	@$(CC) $(CFLAG) $(OBJ) $(LIBS_OBJ) $(MLXFLAGS) -o $(NAME)
	@echo $(CURSIVE)$(GREEN)"$(NAME) was created!"
	
%.o: %.c
	@echo $(CURSIVE)$(GRAY) "     - Making MiniLibx..." $(NONE)
	@$(MAKE) -C mlx_linux
	@echo $(CURSIVE)$(GRAY) "     - Making Object Files..." $(NONE)
	@gcc $(CFLAGS) $(INCLUDE) -c $< -o $@

mlx:
	@sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
	@sudo cp mlx_linux/libmlx.a /usr/local/lib/
	@sudo cp mlx_linux/mlx.h /usr/local/include/

clean:
	@$(MAKE) -C ft_printf clean
	@rm -rf src/*.o
	@rm -rf gnl/*.o
	@echo $(CURSIVE)$(GRAY)"Object files were cleaned"$(NONE)

fclean: clean
	@$(MAKE) -C ft_printf fclean
	@rm -f $(NAME)
	@echo $(CURSIVE)$(GRAY)"So_long was cleaned"$(NONE)
	
re: fclean $(NAME)

.PHONY: all clean fclean re
