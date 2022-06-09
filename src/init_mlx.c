/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:13:10 by erickbarros       #+#    #+#             */
/*   Updated: 2022/06/09 01:31:16 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_mlx(t_list *map, t_map *map_info)
{
	t_data	mlx_data;
	int		width;
	int		heigth;

	width = map_info->map_length * 64;
	heigth = map_info->map_heigth * 64;	
	mlx_data.mlx = mlx_init();
	mlx_data.win = mlx_new_window(mlx_data.mlx, width, heigth, "So_Long");
	draw_map(&mlx_data, map_info, map);
	mlx_loop(mlx_data.mlx);
	map = map->next; //REMOVEEEE
}
