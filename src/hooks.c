/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:55:59 by erickbarros       #+#    #+#             */
/*   Updated: 2022/06/16 06:11:42 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == MAIN_PAD_ESC)
		exit_clean(data);
	if (keycode == KEY_UP)
		move_player(data, KEY_UP);
	if (keycode == KEY_DOWN)
		move_player(data, KEY_DOWN);
	if (keycode == KEY_LEFT)
		move_player(data, KEY_LEFT);
	if (keycode == KEY_RIGHT)
		move_player(data, KEY_RIGHT);
	return (0);
}

int	move_player(t_data *data, int direction)
{
	if (direction == KEY_UP)
		data->player.y--;
	if (direction == KEY_DOWN)
		data->player.y++;
	if (direction == KEY_RIGHT)
		data->player.x++;
	if (direction == KEY_LEFT)
		data->player.x--;
	print_player(data);
	return (0);
}

void	print_player(t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, data->map_info.player,
			&data->img_width, &data->img_heigth);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->length, &data->endian);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img, data->player.x * (data->img_width - 1), data->player.y * (data->img_heigth - 1));	
}
