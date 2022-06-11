/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 01:06:54 by erickbarros       #+#    #+#             */
/*   Updated: 2022/06/11 03:32:17 by erickbarros      ###   ########.fr       */
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
			if (line[x] == '1')
			{
				data->img = mlx_xpm_file_to_image(data->mlx, map_info->wall, &data->img_width, &data->img_heigth);
				data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
				mlx_put_image_to_window(data->mlx, data->win, data->img, x * 64, y * 64);
			}
			x++;
		}
		y++;
		tmp = tmp->next;
		free (line);
	}
}
