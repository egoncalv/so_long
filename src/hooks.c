/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:55:59 by erickbarros       #+#    #+#             */
/*   Updated: 2022/06/16 06:31:08 by erickbarros      ###   ########.fr       */
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
	{
		data->map[data->player.y][data->player.x] = '0';
		data->player.y--;
		data->map[data->player.y][data->player.x] = 'P';
	}
	if (direction == KEY_DOWN)
	{
		data->map[data->player.y][data->player.x] = '0';
		data->player.y++;
		data->map[data->player.y][data->player.x] = 'P';
	}
	if (direction == KEY_RIGHT)
	{
		data->map[data->player.y][data->player.x] = '0';
		data->player.x++;
		data->map[data->player.y][data->player.x] = 'P';
	}
	if (direction == KEY_LEFT)
	{
		data->map[data->player.y][data->player.x] = '0';
		data->player.x--;
		data->map[data->player.y][data->player.x] = 'P';
	}
	draw_map(data); 
	return (0);
}
