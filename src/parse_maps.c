/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 07:34:07 by egoncalv          #+#    #+#             */
/*   Updated: 2022/06/16 05:43:13 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// This function reads from the given map into a 2d array
// and calls other functions that will parse
// the map to verify it.
void	parse_maps(t_data *data)
{
	int		fd;
	int		count;
	t_pos	pos;

	data->map = malloc(sizeof(char **) * count_lines(data->argv) + 1);
	if (!data->map)
		exit_error("Failed to allocate memory");
	fd = open(data->argv, O_RDONLY);
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
//one exit and one player in the map, sets their positions and returns an 
//error if any element is missing.
void	check_elements(t_data *data, char *line, int cur_line)
{
	static int	collectibles;
	int			x;

	x = 0;
	while (line[x])
	{
		if (line[x] == 'P')
			set_position(data, x, cur_line, line[x]);
		else if (line[x] == 'C')
			collectibles++;
		else if (line[x] == 'E')
			set_position(data, x, cur_line, line[x]);
		x++;
	}
	if (cur_line == ft_lstsize(data->map))
	{
		if (data->player.quantity != 1)
			exit_error("The map needs one player!");
		if (data->exit.quantity != 1)
			exit_error("The map needs one exit!");
		if (collectibles < 1)
			exit_error("The map needs at least one collectible!");
	}
}
