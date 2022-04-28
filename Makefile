# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/28 01:09:23 by egoncalv          #+#    #+#              #
#    Updated: 2022/04/28 02:23:23 by egoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -Lmlx -framework OpenGL -framework AppKit

NAME = so_long

SRC =	src/main.c \
		src/start.c \
		src/utils.c \

OBJ = $(SRC:.c=.o)

LIBS_OBJ =	ft_printf/src/*.o \
			ft_printf/libft/*.o \

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C mlx
	@$(MAKE) -C ft_printf
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) $(LIBS_OBJ) -o $(NAME)
	@mv mlx/libmlx.dylib .
	@echo "$(NAME) was created!"
	
%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C mlx clean
	@$(MAKE) -C ft_printf clean
	@echo "Object files were cleaned"

fclean: clean
	@$(MAKE) -C mlx clean
	@$(MAKE) -C ft_printf fclean
	@rm -f $(NAME)
	@rm -f libmlx.dylib
	@$(NAME) was cleaned
	
re: fclean $(NAME)

.PHONY: all clean fclean re
