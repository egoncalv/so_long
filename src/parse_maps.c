/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 07:34:07 by egoncalv          #+#    #+#             */
/*   Updated: 2022/06/08 11:16:47 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// This function creates a linked list and places a line by node,
// for each line of the given map.
void	parse_maps(char *argv, t_list *map)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_lstadd_back(&map, ft_lstnew(line));
	}
	free(line);
	evaluate_maps(map);
}

void	evaluate_maps(t_list *map)
{
	int			x;
	int			cur_line;
	int			map_length;
	int			last_line;
	char		*line;

	map_length = ft_strlen(map->content);
	last_line = ft_lstsize(map) + 3;
	cur_line = 0;
	while (map)
	{
		x = 0;
		line = ft_strdup(map->content);
		check_walls(line, map_length, cur_line, last_line);
		
		cur_line++;
		map = map->next;
	}
	free(line);
}

//This function checks if the map is surrounded
//by walls, and returns an error if not
void	check_walls(char *line, int map_length, int cur_line, int last_line)
{
	int	x;

	x = 0;
	if (cur_line == 0 || cur_line == last_line)
	{
		while (line[x] != '\n')
		{
			if (line[x] != '1' && line[x] != '\n')
				exit_error("The map must be surrounded by Walls!");
			x++;
		}
	}
	if ((int)ft_strlen(line) != map_length)
		exit_error("The map must be rectangular!");
	if (line[0] != '1')
		exit_error("The map must be surrounded by Walls!");
	if (line[map_length - 2] != '1')
		exit_error("The map must be surrounded by Walls!");
}
