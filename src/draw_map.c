/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 01:06:54 by erickbarros       #+#    #+#             */
/*   Updated: 2022/06/09 01:45:00 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_map(t_data *mlx_data, t_map *map_info, t_list *map)
{
	int		x;
	int		y;
	char	*line;

	x = 0;
	y = 0;
	while (map)
	{
		line = ft_strdup(map->content);
		while (line[x])
		{
			mlx_data->img = mlx_xpm_file_to_image(mlx_data->mlx, map_info->wall_sprint, &mlx_data->img_width, &mlx_data->img_heigth);
			mlx_data->addr = mlx_get_data_addr(mlx_data->img, &mlx_data->bits_per_pixel, &mlx_data->line_length, &mlx_data->endian);
			mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img, 0, 0);
			x++;
		}
		y++;
		map = map->next;
		free (line);
	}
}
