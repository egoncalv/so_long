/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 01:06:54 by erickbarros       #+#    #+#             */
/*   Updated: 2022/11/08 19:44:22 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_map(t_data *data)
{
	t_pos	pos;
	char	*steps;

	pos.y = 0;
	while (pos.y < data->map_info.map_heigth)
	{
		pos.x = 0;
		while (data->map[pos.y][pos.x])
		{
			choose_tile(data, data->map[pos.y][pos.x]);
			mlx_put_image_to_window(data->mlx, data->win,
				data->img, pos.x * (data->img_width - 1), pos.y
				* (data->img_heigth - 1));
			pos.x++;
		}
		pos.y++;
	}
	steps = ft_itoa(data->steps);
	mlx_string_put(data->mlx, data->win, 10, 10, 0XFFFFFF, steps);
	free(steps);
}

void	choose_tile(t_data *data, char c)
{
	char	*tile;

	tile = 0;
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
	{
		if (c == '1')
			tile = ft_strdup(data->map_info.wall);
		if (c == '0')
			tile = ft_strdup(data->map_info.empty);
		if (c == 'P')
			tile = ft_strdup(data->map_info.player);
		if (c == 'C')
			tile = ft_strdup(data->map_info.collect);
		if (c == 'E')
			tile = ft_strdup(data->map_info.exit);
		data->img = mlx_xpm_file_to_image(data->mlx, tile,
				&data->img_width, &data->img_heigth);
	}
	free (tile);
}
