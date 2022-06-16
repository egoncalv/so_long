/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 01:06:54 by erickbarros       #+#    #+#             */
/*   Updated: 2022/06/16 03:56:51 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_map(t_data *data)
{
	int		x;
	int		y;
	char	*line;
	t_list	*tmp;

	y = 0;
	tmp = data->map;
	while (tmp)
	{
		x = 0;
		line = ft_strdup(tmp->content);
		while (line[x])
		{
			choose_tile(line[x], data);
			mlx_put_image_to_window(data->mlx, data->win,
				data->img, x * (data->img_width - 1), y * (data->img_heigth - 1));
			x++;
		}
		y++;
		tmp = tmp->next;
		free (line);
	}
}

void	choose_tile(char c, t_data *data)
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
		data->addr = mlx_get_data_addr(data->img, &data->bpp,
				&data->length, &data->endian);
	}
	free (tile);
}
