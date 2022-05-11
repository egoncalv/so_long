/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 07:34:07 by egoncalv          #+#    #+#             */
/*   Updated: 2022/05/04 00:31:57 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_tile	*new_map(char *read)
{
	t_tile new;

	new = (t_tile *)malloc(sizeof(t_tile))
	if (!new)
		return (new = NULL);
	new->type = read;
	new->left = NULL;
	new->right = NULL;
	new->down = NULL;
	new->up = NULL;
	return (new);
}

void	*new_tile(char *read, t_tile previous)
{
		
}

int	parse_maps(char	*argv)
{
	t_tile	map;
	char	*line;
	int		i;
	
	tile.fd = open(argv, O_RDONLY);
	line = get_next_line(tile.fd);
	map = new_map(line[0])
	i = 1;
	while (line[++i] != 0)
	{
		if (line[i] != 1)
			return (0);
		tile.type = "wall";
	}
	return (1);
}
