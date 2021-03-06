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

CFLAGS = -Wall -Wextra -Werror -g

MLXFLAGS = -lmlx -Lmlx -framework OpenGL -framework AppKit

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

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Making mlx..." $(NONE)
	@$(MAKE) -C mlx
	@echo $(CURSIVE)$(GRAY) "     - Making ft_printf..." $(NONE)
	@$(MAKE) -C ft_printf
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)" $(NONE)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) $(LIBS_OBJ) -o $(NAME)
	@mv mlx/libmlx.dylib .
	@echo $(CURSIVE)$(GREEN)"$(NAME) was created!"
	
%.o: %.c
	@echo $(CURSIVE)$(GRAY) "     - Making Object Files..." $(NONE)
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C mlx clean
	@$(MAKE) -C ft_printf clean
	@rm -rf src/*.o
	@rm -rf gnl/*.o
	@echo $(CURSIVE)$(GRAY)"Object files were cleaned"$(NONE)

fclean: clean
	@$(MAKE) -C mlx clean
	@$(MAKE) -C ft_printf fclean
	@rm -f $(NAME)
	@rm -f libmlx.dylib
	@echo $(CURSIVE)$(GRAY)"So_long was cleaned"$(NONE)
	
re: fclean $(NAME)

.PHONY: all clean fclean re
