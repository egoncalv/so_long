/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 07:34:07 by egoncalv          #+#    #+#             */
/*   Updated: 2022/06/16 01:28:12 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// This function creates a linked list and places a line by node,
// for each line of the given map.
void	parse_maps(char *argv, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_lstadd_back(&data->map, ft_lstnew(line));
	}
	free(line);
	set_map(data);
	evaluate_maps(data);
}

//Iterates through the map (linked list), and invokes the functions
//to verify if the map is valid or not.
void	evaluate_maps(t_data *data)
{
	int			cur_line;
	char		*line;
	t_list		*tmp;

	tmp = data->map;
	cur_line = 0;
	while (tmp)
	{
		line = ft_strdup(tmp->content);
		check_walls(data, line, cur_line);
		check_elements(data, line, cur_line);
		tmp = tmp->next;
		cur_line++;
	}
	free(line);
	free(tmp);
}

//Checks if the map is surrounded
//by walls, and returns an error if not
void	check_walls(t_data *data, char *line, int cur_line)
{
	int	x;

	x = 0;
	if (cur_line == 0 || cur_line == ft_lstsize(data->map))
	{
		while (line[x] != '\n')
		{
			if (line[x] != '1' && line[x] != '\n')
				exit_error("The map must be surrounded by Walls!");
			x++;
		}
	}
	if ((int)ft_strlen(line) != data->map_info.map_length)
		exit_error("The map must be rectangular!");
	if (line[0] != '1')
		exit_error("The map must be surrounded by Walls!");
	if (line[data->map_info.map_length - 2] != '1')
		exit_error("The map must be surrounded by Walls!");
}

/*Checks if there is at least one collectible, 
one exit and one player in the map, sets their positions and returns an 
error if any element is missing.*/
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
