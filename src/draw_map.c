/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 01:06:54 by erickbarros       #+#    #+#             */
/*   Updated: 2022/11/09 15:43:09 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_map(t_data *data)
{
	t_pos	pos;

	pos.y = 0;
	while (pos.y < data->map_info.map_heigth)
	{
		pos.x = 0;
		while (data->map[pos.y][pos.x])
		{	
			choose_tile(data, data->map[pos.y][pos.x], pos);
			pos.x++;
		}
		pos.y++;
	}
}

void	choose_tile(t_data *data, char c, t_pos pos)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
	{
		if (c == '1')
			mlx_put_image_to_window(data->mlx, data->win,
				data->map_info.wall, pos.x * (data->img_width), pos.y
				* (data->img_heigth));
		if (c == '0')
			mlx_put_image_to_window(data->mlx, data->win,
				data->map_info.empty, pos.x * (data->img_width), pos.y
				* (data->img_heigth));
		if (c == 'P')
			mlx_put_image_to_window(data->mlx, data->win,
				data->map_info.player, pos.x * (data->img_width), pos.y
				* (data->img_heigth));
		if (c == 'C')
			mlx_put_image_to_window(data->mlx, data->win,
				data->map_info.collect, pos.x * (data->img_width), pos.y
				* (data->img_heigth));
		if (c == 'E')
			mlx_put_image_to_window(data->mlx, data->win,
				data->map_info.exit, pos.x * (data->img_width), pos.y
				* (data->img_heigth));
	}
}
