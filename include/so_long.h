/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:01:00 by egoncalv          #+#    #+#             */
/*   Updated: 2022/05/04 00:23:13 by erickbarros      ###   ########.fr       */
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
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_heigth;
}				t_data;

typedef struct s_tile
{
	char	type[10];
	s_tile	*right;
	s_tile	*left;
	s_tile	*down;
	s_tile	*up;
}			t_tile;

void	my_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		parse_maps(char	*argv);

#endif
