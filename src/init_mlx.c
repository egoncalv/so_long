/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:13:10 by erickbarros       #+#    #+#             */
/*   Updated: 2022/06/15 19:26:15 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_mlx(t_data *data)
{
	int		width;
	int		heigth;

	width = (data->map_info.map_length - 1) * 64;
	heigth = data->map_info.map_heigth * 64;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, width, heigth, "so_long");
	draw_map(data);
	mlx_loop(data->mlx);
}
