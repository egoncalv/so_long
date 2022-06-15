/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:57:20 by egoncalv          #+#    #+#             */
/*   Updated: 2022/06/14 02:37:57 by erickbarros      ###   ########.fr       */
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

void	set_map(t_map *map_info, t_list *map)
{
	map_info->map_length = ft_strlen(map->content);
	map_info->map_heigth = ft_lstsize(map);
	map_info->wall = "./assets/wall.xpm";
	map_info->player = "./assets/player.xpm";
	map_info->empty = "./assets/wood.xpm";
	map_info->collect = "./assets/collectible.xpm";
	map_info->exit = "./assets/door.xpm";
}
