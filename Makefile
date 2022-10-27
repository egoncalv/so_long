# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/28 01:09:23 by egoncalv          #+#    #+#              #
#    Updated: 2022/10/26 17:43:55 by egoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -g

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
		src/find_path.c \
		src/queue_utils.c \

OBJ = $(SRC:.c=.o)

LIBS_OBJ =	ft_printf/src/*.o \
			ft_printf/libft/*.o \

all: $(NAME)

$(NAME): $(OBJ)
	@echo "     - Making ft_printf..."
	@$(MAKE) -C ft_printf
	@echo "     - Compiling $(NAME)"
	@$(CC) $(CFLAG) $(OBJ) $(LIBS_OBJ) $(MLXFLAGS) -o $(NAME)
	@echo "$(NAME) was created!"
	
%.o: %.c
	@echo "     - Making MiniLibx..." 
	@$(MAKE) -C mlx_linux
	@echo "     - Making Object Files..."
	@gcc $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@$(MAKE) -C ft_printf clean
	@rm -rf src/*.o
	@rm -rf gnl/*.o
	@echo "Object files were cleaned"

fclean: clean
	@$(MAKE) -C ft_printf fclean
	@rm -f $(NAME)
	@echo "So_long was cleaned"
	
re: fclean $(NAME)

.PHONY: all clean fclean re
