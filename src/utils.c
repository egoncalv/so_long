/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:57:20 by egoncalv          #+#    #+#             */
/*   Updated: 2022/06/15 19:25:48 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_extension(char *file, int argc)
{
	char	*extension;

	if (argc < 2)
		exit_error("You must pass one valid map as argument!");
	extension = ft_strrchr(file, '.');
	if (!extension || ft_strncmp(extension, ".ber", 4) != 0)
		exit_error("The map needs a .ber extension!");
}

void	set_map(t_data *data)
{
	data->map_info.map_length = ft_strlen(data->map->content);
	data->map_info.map_heigth = ft_lstsize(data->map);
	data->map_info.wall = "./assets/wall.xpm";
	data->map_info.player = "./assets/player.xpm";
	data->map_info.empty = "./assets/wood.xpm";
	data->map_info.collect = "./assets/collectible.xpm";
	data->map_info.exit = "./assets/door.xpm";
}
