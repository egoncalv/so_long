/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 07:34:07 by egoncalv          #+#    #+#             */
/*   Updated: 2022/10/27 01:12:34 by egoncalv         ###   ########.fr       */
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

	data->map = malloc(sizeof(*data->map) * count_lines(data->argv));
	if (!data->map)
		exit_error("Failed to allocate memory", data);
	fd = open(data->argv, O_RDONLY);
	if (fd < 0)
		exit_error("The map does not exist", data);
	pos.y = 0;
	data->map[pos.y] = get_next_line(fd);
	while (data->map[pos.y])
		data->map[++pos.y] = get_next_line(fd);
	close(fd);
	set_map(data);
	check_walls(data);
	check_player(data);
	check_elements(data);
	if (find_path(data, data->map_info.exit_y, data->map_info.exit_x) == 0)
		exit_error("Exit not reachable. There is no valid path", data);
	else
		ft_printf("Valid Map");
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
			exit_error("The map must be rectangular!", data);
		if (pos.y == 0 || pos.y == data->map_info.map_heigth - 1)
		{
			while (data->map[pos.y][pos.x] != '\n')
			{
				if (data->map[pos.y][pos.x] != '1' &&
					data->map[pos.y][pos.x] != '\n')
					exit_error("The map must be surrounded by Walls!", data);
				pos.x++;
			}
		}
		if (data->map[pos.y][0] != '1' ||
			data->map[pos.y][data->map_info.map_length - 2] != '1')
			exit_error("The map must be surrounded by Walls!", data);
		pos.y++;
	}
}

//Check if there is only and at least one player in the map
void	check_player(t_data *data)
{
	t_pos	pos;

	pos.y = 0;
	data->player.quantity = 0;
	while (data->map[pos.y])
	{
		pos.x = 0;
		while (data->map[pos.y][pos.x])
		{
			if (data->map[pos.y][pos.x] == 'P')
				set_player_position(data, pos.x, pos.y, 'P');
			pos.x++;
		}
		pos.y++;
	}
	if (data->player.quantity != 1)
		exit_error("The map is not valid", data);
}

//Checks if there is at least one collectible 
//and only one exit in the map and returns an 
//error if any element is missing or exceeding.
void	check_elements(t_data *data)
{
	t_pos		pos;
	static int	exit;

	data->collectibles = 0;
	pos.y = 0;
	while (data->map[pos.y])
	{
		pos.x = 0;
		while (data->map[pos.y][pos.x])
		{
			if (data->map[pos.y][pos.x] == 'C')
			{
				if (!find_path(data, pos.y, pos.x))
					exit_error("A collectible is not reachable", data);
				data->collectibles++;
			}
			else if (data->map[pos.y][pos.x] == 'E')
			{
				data->map_info.exit_y = pos.y;
				data->map_info.exit_x = pos.x;
				exit++;
			}
			pos.x++;
		}
		pos.y++;
	}
	if (exit != 1 || data->collectibles < 1)
		exit_error("The map is not valid", data);
}
