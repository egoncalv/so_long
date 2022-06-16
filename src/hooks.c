/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:55:59 by erickbarros       #+#    #+#             */
/*   Updated: 2022/06/16 07:13:16 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, t_data *data)
{
	static int	count;

	if (keycode == MAIN_PAD_ESC)
		exit_clean(data);
	if (keycode == KEY_UP)
		move_player(data, KEY_UP);
	if (keycode == KEY_DOWN)
		move_player(data, KEY_DOWN);
	if (keycode == KEY_LEFT)
	{
		move_player(data, KEY_LEFT);
		data->map_info.player = "./assets/player_left.xpm";
	}
	if (keycode == KEY_RIGHT)
	{
		move_player(data, KEY_RIGHT);
		data->map_info.player = "./assets/player.xpm";
	}
	data->map[data->player.y][data->player.x] = 'P';
	ft_printf("Steps count: %d\n", count++);
	draw_map(data);
	return (0);
}

void	move_player(t_data *data, int direction)
{
	data->map[data->player.y][data->player.x] = '0';
	if (direction == KEY_UP
		&& data->map[data->player.y - 1][data->player.x] != '1')
		data->player.y--;
	if (direction == KEY_DOWN
		&& data->map[data->player.y + 1][data->player.x] != '1')
		data->player.y++;
	if (direction == KEY_RIGHT
		&& data->map[data->player.y][data->player.x + 1] != '1')
		data->player.x++;
	if (direction == KEY_LEFT
		&& data->map[data->player.y][data->player.x - 1] != '1')
		data->player.x--;
	verify_object(data);
}

void	verify_object(t_data *data)
{
	if (data->map[data->player.y][data->player.x] == 'C')
		data->player.collected++;
	if (data->map[data->player.y][data->player.x] == 'E'
		&& data->player.collected == data->collectibles)
		exit_clean(data);
}
