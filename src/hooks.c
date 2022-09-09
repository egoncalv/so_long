/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:55:59 by erickbarros       #+#    #+#             */
/*   Updated: 2022/09/09 17:59:42 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == MAIN_PAD_ESC)
		exit_clean(data);
	if (keycode == KEY_UP)
		move_up(data);
	if (keycode == KEY_DOWN)
		move_down(data);
	if (keycode == KEY_LEFT)
	{
		move_left(data);
		data->map_info.player = "./assets/player_left.xpm";
	}
	if (keycode == KEY_RIGHT)
	{	
		move_right(data);
		data->map_info.player = "./assets/player.xpm";
	}
	draw_map(data);
	return (0);
}

//This function verifies if the player gets an collectable or if it is on the exit.

void	verify_object(t_data *data)
{
	if (data->map[data->player.y][data->player.x] == 'C')
		data->player.collected++;
	if (data->map[data->player.y][data->player.x] == 'E'
		&& data->player.collected == data->collectibles)
		exit_clean(data);
}
