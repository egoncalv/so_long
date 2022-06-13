/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:13:10 by erickbarros       #+#    #+#             */
/*   Updated: 2022/06/13 18:01:17 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_mlx(t_list *map, t_map *map_info)
{
	t_data	data;
	int		width;
	int		heigth;

	width = (map_info->map_length - 1) * 64;
	heigth = map_info->map_heigth * 64;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, width, heigth, "So_Long");
	draw_map(&data, map_info, map);
	mlx_loop(data.mlx);
}
