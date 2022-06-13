/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:01:00 by egoncalv          #+#    #+#             */
/*   Updated: 2022/06/13 19:28:33 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "keys_macos.h"
# include "../mlx/mlx.h"
# include "../ft_printf/includes/ft_printf.h"
# include "../gnl/get_next_line.h"
# include <fcntl.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
	int		img_width;
	int		img_heigth;
}				t_data;

typedef struct s_map
{
	int		map_length;
	int		map_heigth;
	char	*wall;
	char	*player;
	char	*empty;
	char	*collect;
	char	*exit;
}			   t_map;

typedef struct s_player
{
	int	initial_x;
	int	initial_y;
}				t_player;

void	my_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
t_list	*parse_maps(char *argv, t_list *map, t_map *map_info);
void	evaluate_maps(t_list *map);
void	check_walls(char *line, int map_length, int cur_line, int last_line);
void	check_elements(char *line, int cur_line, int last_line);
void	check_extension(char *file, int argc);
void	exit_error(char *error_message);
void	init_mlx(t_list *map, t_map *map_info);
void	set_map(t_map *map_info, t_list *map);
void	draw_map(t_data *mlx_data, t_map *map_info, t_list *map);
void	print_tile(char c, t_map *map_info, t_data *data);

#endif
