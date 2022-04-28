/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:01:00 by egoncalv          #+#    #+#             */
/*   Updated: 2022/04/28 07:43:56 by egoncalv         ###   ########.fr       */
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

typedef struct s_map
{
	int	fd;
}			t_map;

void	my_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		parse_maps(char	*argv);

#endif
