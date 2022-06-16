/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:01:00 by egoncalv          #+#    #+#             */
/*   Updated: 2022/06/16 01:27:00 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "keys_macos.h"
# include "../mlx/mlx.h"
# include "../ft_printf/includes/ft_printf.h"
# include "../gnl/get_next_line.h"
# include <fcntl.h>

typedef struct s_map
{
	int		map_length;
	int		map_heigth;
	int		exit_x;
	int		exit_y;
	char	*wall;
	char	*player;
	char	*empty;
	char	*collect;
	char	*exit;
}			   t_map;

typedef struct s_object
{
	int	quantity;
	int	x;
	int	y;
}				t_object;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			length;
	int			endian;
	int			img_width;
	int			img_heigth;
	t_object	player;
	t_object	exit;
	t_list		*map;
	t_map		map_info;
}				t_data;

void	my_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
void	parse_maps(char *argv, t_data *data);
void	evaluate_maps(t_data *data);
void	check_walls(t_data *data, char *line, int cur_line);
void	check_elements(t_data *data, char *line, int cur_line);
void	check_extension(char *file, int argc);
void	exit_error(char *error_message);
void	init_mlx(t_data *data);
void	set_map(t_data *data);
void	draw_map(t_data *data);
void	choose_tile(char c, t_data *data);
void	set_position(t_data *data, int x, int y, char element);

#endif
