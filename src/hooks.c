/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:55:59 by erickbarros       #+#    #+#             */
/*   Updated: 2022/11/09 12:31:20 by egoncalv         ###   ########.fr       */
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
		free (data->map_info.player);
		data->map_info.player = mlx_xpm_file_to_image(data->mlx, "./assets/player_left.xpm", &data->img_width, &data->img_heigth);
	}
	if (keycode == KEY_RIGHT)
	{	
		move_right(data);
		free (data->map_info.player);
		data->map_info.player = mlx_xpm_file_to_image(data->mlx, "./assets/player.xpm", &data->img_width, &data->img_heigth);
	}
	draw_map(data);
	return (0);
}

//This function verifies if the player
//gets an collectable or if it is on the exit.

void	verify_object(t_data *data)
{
	if (data->map[data->player.y][data->player.x] == 'C')
		data->player.collected++;
	if (data->map[data->player.y][data->player.x] == 'E'
		&& data->player.collected == data->collectibles)
		exit_clean(data);
}
