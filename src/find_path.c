/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:00:54 by egoncalv          #+#    #+#             */
/*   Updated: 2022/10/24 16:07:19 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	find_path(t_data *data)
{
	char	**visited;
	t_pos	pos;
	

	visited = malloc(sizeof(char *) * data->map_info.map_heigth);
	if (!visited)
		exit_error("Malloc Error");
	pos.y = 0;
	while (pos.y < data->map_info.map_heigth)
	{
		visited[pos.y] = malloc(sizeof(char) * data->map_info.map_length + 1);
		if (!visited[pos.y])
			exit_error("Malloc Error");
		ft_memset(visited[pos.y], '0', data->map_info.map_length - 1);
		visited[pos.y][data->map_info.map_length - 1] = '\n';
		visited[pos.y][data->map_info.map_length] = 0;
		pos.y++;
	}
	visited[data->map_info.map_heigth] = 0;
	pos.y = 0;
	visited[data->player.y][data->player.x] = 'P';
	while (visited[pos.y])
	{
		ft_printf("%s", visited[pos.y]);
		pos.y++;
	}
	return (1);
}
