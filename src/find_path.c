/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:00:54 by egoncalv          #+#    #+#             */
/*   Updated: 2022/10/24 17:12:31 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	find_path(t_data *data)
{
	char	**visited;
	t_pos	pos;
	
	visited = 0;
	visited = create_array(visited, data);
	pos.y = data->player.y;
	pos.x = data->player.x;
	//create queue using linked lists
	return (1);
}

char	**create_array(char **array, t_data *data)
{
	int	i;
	array = malloc(sizeof(char *) * data->map_info.map_heigth);
	if (!array)
		exit_error("Malloc Error");
	i = 0;
	while (i < data->map_info.map_heigth)
	{
		array[i] = malloc(sizeof(char) * data->map_info.map_length + 1);
		if (!array[i])
			exit_error("Malloc Error");
		ft_memset(array[i], '0', data->map_info.map_length - 1);
		array[i][data->map_info.map_length - 1] = '\n';
		array[i][data->map_info.map_length] = 0;
		i++;
	}
	array[data->map_info.map_heigth] = 0;
	return (array);
}
