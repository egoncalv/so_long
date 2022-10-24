/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:01:00 by egoncalv          #+#    #+#             */
/*   Updated: 2022/10/24 17:03:06 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "keys_linux.h"
# include "../ft_printf/includes/ft_printf.h"
# include "../gnl/get_next_line.h"
# include <mlx.h>
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
}				t_map;

typedef struct s_object
{
	int	quantity;
	int	x;
	int	y;
	int	collected;
}				t_object;

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int		bpp;
	int		length;
	int		endian;
	int		img_width;
	int		img_heigth;
	char		*argv;
	char		**map;
	t_object	player;
	int		collectibles;
	int		steps;
	t_map		map_info;
}				t_data;

void	parse_maps(t_data *data);
int		count_lines(char *argv);
void	check_walls(t_data *data);
void	check_elements(t_data *data);
void	check_extension(char *file, int argc);
void	exit_error(char *error_message);
int		exit_clean(t_data *data);
void	init_mlx(t_data *data);
void	set_map(t_data *data);
void	draw_map(t_data *data);
void	choose_tile(t_data *data, char c);
void	set_player_position(t_data *data, int x, int y, char element);
int		key_hook(int keycode, t_data *data);
void	verify_object(t_data *data);
int		avoid_wall(t_data *data, int direction);
int		move_up(t_data *data);
int		move_down(t_data *data);
int		move_left(t_data *data);
int		move_right(t_data *data);
int		find_path(t_data *data);
char	**create_array(char **array, t_data *data);

#endif
