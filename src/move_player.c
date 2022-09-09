/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:23:16 by erickbarros       #+#    #+#             */
/*   Updated: 2022/09/09 17:58:25 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//These functions are called when one of the keys responsible for moving the player
//are pressed. They verify if the movement is possible, then change the array containing the map.

int	move_up(t_data *data)
{
	if (data->player.collected != data->collectibles
		&& data->map[data->player.y - 1][data->player.x] == 'E')
		return (0);
	if (data->map[data->player.y - 1][data->player.x] != '1')
	{
		data->map[data->player.y][data->player.x] = '0';
		data->player.y--;
		verify_object(data);
		data->map[data->player.y][data->player.x] = 'P';
		ft_printf("\nSteps Count: %d", data->steps++);
		return (1);
	}
	return (0);
}

int	move_down(t_data *data)
{
	if (data->player.collected != data->collectibles
		&& data->map[data->player.y + 1][data->player.x] == 'E')
		return (0);
	if (data->map[data->player.y + 1][data->player.x] != '1')
	{
		data->map[data->player.y][data->player.x] = '0';
		data->player.y++;
		verify_object(data);
		data->map[data->player.y][data->player.x] = 'P';
		ft_printf("\nSteps Count: %d", data->steps++);
		return (1);
	}
	return (0);
}

int	move_left(t_data *data)
{
	if (data->player.collected != data->collectibles
		&& data->map[data->player.y][data->player.x - 1] == 'E')
		return (0);
	if (data->map[data->player.y][data->player.x - 1] != '1')
	{
		data->map[data->player.y][data->player.x] = '0';
		data->player.x--;
		verify_object(data);
		data->map[data->player.y][data->player.x] = 'P';
		ft_printf("\nSteps Count: %d", data->steps++);
		return (1);
	}
	return (0);
}

int	move_right(t_data *data)
{
	if (data->player.collected != data->collectibles
		&& data->map[data->player.y][data->player.x + 1] == 'E')
		return (0);
	if (data->map[data->player.y][data->player.x + 1] != '1')
	{
		data->map[data->player.y][data->player.x] = '0';
		data->player.x++;
		verify_object(data);
		data->map[data->player.y][data->player.x] = 'P';
		ft_printf("\nSteps Count: %d", data->steps++);
		return (1);
	}
	return (0);
}
