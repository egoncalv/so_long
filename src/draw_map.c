/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 01:06:54 by erickbarros       #+#    #+#             */
/*   Updated: 2022/06/13 19:31:43 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_map(t_data *data, t_map *map_info, t_list *map)
{
	int		x;
	int		y;
	char	*line;
	t_list	*tmp;

	y = 0;
	tmp = map;
	while (tmp)
	{
		x = 0;
		line = ft_strdup(tmp->content);
		while (line[x])
		{
			print_tile(line[x], map_info, data);
			mlx_put_image_to_window(data->mlx, data->win,
				data->img, x * 64, y * 64);
			x++;
		}
		y++;
		tmp = tmp->next;
		free (line);
	}
}

void	print_tile(char c, t_map *map_info, t_data *data)
{
	char	*tile;

	tile = 0;
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
	{
		if (c == '1')
			tile = ft_strdup(map_info->wall);
		if (c == '0')
			tile = ft_strdup(map_info->empty);
		if (c == 'P')
			tile = ft_strdup(map_info->player);
		if (c == 'C')
			tile = ft_strdup(map_info->collect);
		if (c == 'E')
			tile = ft_strdup(map_info->exit);
		data->img = mlx_xpm_file_to_image(data->mlx, tile,
				&data->img_width, &data->img_heigth);
		data->addr = mlx_get_data_addr(data->img, &data->bpp,
				&data->length, &data->endian);
	}
	free (tile);
}
