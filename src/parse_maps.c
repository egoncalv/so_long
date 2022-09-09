/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 07:34:07 by egoncalv          #+#    #+#             */
/*   Updated: 2022/09/09 17:55:44 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// This function reads from the given map into a 2d array
// and calls other functions that will parse
// the map to verify it.
void	parse_maps(t_data *data)
{
	int		fd;
	t_pos	pos;

	data->map = malloc(sizeof(char **) * count_lines(data->argv) + 1);
	if (!data->map)
		exit_error("Failed to allocate memory");
	fd = open(data->argv, O_RDONLY);
	if (fd < 0)
		exit_error("The map does not exist");
	pos.y = 0;
	while (1)
	{
		data->map[pos.y] = get_next_line(fd);
		if (data->map[pos.y] == 0)
			break ;
		pos.y++;
	}
	close(fd);
	set_map(data);
	check_walls(data);
	check_elements(data);
}

//Checks if the map is surrounded
//by walls, and returns an error if not
void	check_walls(t_data *data)
{
	t_pos	pos;

	pos.y = 0;
	while (data->map[pos.y] != 0)
	{
		pos.x = 0;
		if ((int)ft_strlen(data->map[pos.y]) != data->map_info.map_length)
			exit_error("The map must be rectangular!");
		if (pos.y == 0 || pos.y == data->map_info.map_heigth - 1)
		{
			while (data->map[pos.y][pos.x] != '\n')
			{
				if (data->map[pos.y][pos.x] != '1' &&
					data->map[pos.y][pos.x] != '\n')
					exit_error("The map must be surrounded by Walls!");
				pos.x++;
			}
		}
		if (data->map[pos.y][0] != '1' ||
			data->map[pos.y][data->map_info.map_length - 2] != '1')
			exit_error("The map must be surrounded by Walls!");
		pos.y++;
	}
}

//Checks if there is at least one collectible, 
//only one exit and only one player in the map and returns an 
//error if any element is missing or exceeding.
void	check_elements(t_data *data)
{
	t_pos		pos;
	static int	exit;

	data->player.quantity = 0;
	data->collectibles = 0;
	pos.y = 0;
	while (data->map[pos.y])
	{
		pos.x = 0;
		while (data->map[pos.y][pos.x])
		{
			if (data->map[pos.y][pos.x] == 'P')
				set_player_position(data, pos.x, pos.y, 'P');
			else if (data->map[pos.y][pos.x] == 'C')
				data->collectibles++;
			else if (data->map[pos.y][pos.x] == 'E')
				exit++;
			pos.x++;
		}
		pos.y++;
	}
	if (data->player.quantity != 1 || exit != 1 || data->collectibles < 1)
		exit_error("The map is not valid");
}
