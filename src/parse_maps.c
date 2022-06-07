/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 07:34:07 by egoncalv          #+#    #+#             */
/*   Updated: 2022/06/07 20:00:23 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// This function creates a linked list and places a line by node,
// for each line of the given map.

void	parse_maps(char *argv)
{
	int		fd;
	t_list	*map;
	char	*line;

	fd = open(argv, O_RDONLY);
	map = 0;
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
	int			current_line;
	int			map_length;
	int			last_line;
	char		*line;

	map_length = ft_strlen(map->content);
	last_line = ft_lstsize(map) + 3;
	current_line = 0;
	while (map)
	{
		x = 0;
		line = ft_strdup(map->content);
		check_walls(line, map_length, current_line, last_line);
		while (line[x])
		{
			print_maps(line[x]);
			x++;
		}
		current_line++;
		map = map->next;
	}
	free(line);
}

//This function checks if the map is surrounded by walls, and return an error if not
void	check_walls(char *line, int map_length, int current_line, int last_line)
{
	int	x;

	x = 0;
	if (current_line == 0 || current_line == last_line)
	{
		while (line[x] != '\n')
		{
			if (line[x] != '1' && line[x] != '\n')
				ft_printf("RETURN ERROR 1\n");
			x++;
		}
	}
	if ((int)ft_strlen(line) != map_length)
		ft_printf("RETURN ERROR 2\n");
	if (line[0] != '1')
		ft_printf("RETURN ERROR 3\n");
	if (line[map_length - 2] != '1')
		ft_printf("RETURN ERROR 4\n");
}
