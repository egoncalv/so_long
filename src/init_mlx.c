/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:13:10 by erickbarros       #+#    #+#             */
/*   Updated: 2022/06/19 01:11:48 by erickbarros      ###   ########.fr       */
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
	data->player.collected = 0;
	data->steps = 1;
	draw_map(data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, 0, exit_clean, data);
	mlx_loop(data->mlx);
}
