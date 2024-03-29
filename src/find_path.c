/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:00:54 by egoncalv          #+#    #+#             */
/*   Updated: 2022/11/09 17:26:56 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	find_path(t_data *data, int goal_y, int goal_x)
{
	char	**visited;
	t_queue	*queue;
	t_queue	*head;
	t_pos	*pos;

	pos = malloc(sizeof(t_pos *));
	visited = 0;
	visited = create_array(visited, data);
	pos->y = data->player.y;
	pos->x = data->player.x;
	queue = create_queue(pos, data, 0, 0);
	head = queue;
	while (queue)
	{
		visited[queue->y][queue->x] = '1';
		pos->y = queue->y;
		pos->x = queue->x;
		if (pos->y == goal_y && pos->x == goal_x)
			return (free_dfsmemory(data, visited, head, pos));
		add_node(data, queue, visited, pos);
		queue = queue->next;
	}
	free_dfsmemory(data, visited, head, pos);
	return (0);
}

void	add_node(t_data *data, t_queue *queue, char **visited, t_pos *pos)
{
	if (isvalid(data->map[queue->y + 1][queue->x],
		visited[queue->y + 1][queue->x]))
		ft_queueadd_back(&queue, create_queue(pos, data, 1, 0));
	if (isvalid(data->map[queue->y - 1][queue->x],
		visited[queue->y - 1][queue->x]))
		ft_queueadd_back(&queue, create_queue(pos, data, -1, 0));
	if (isvalid(data->map[queue->y][queue->x + 1],
		visited[queue->y][queue->x + 1]))
		ft_queueadd_back(&queue, create_queue(pos, data, 0, 1));
	if (isvalid(data->map[queue->y][queue->x - 1],
		visited[queue->y][queue->x - 1]))
		ft_queueadd_back(&queue, create_queue(pos, data, 0, -1));
}

char	**create_array(char **array, t_data *data)
{
	int	i;

	array = malloc(sizeof(char *) * data->map_info.map_heigth + 1);
	array[data->map_info.map_heigth - 1] = "\0";
	if (!array)
		exit_error("Malloc Error", data);
	i = 0;
	while (i < data->map_info.map_heigth)
	{
		array[i] = malloc(sizeof(char) * data->map_info.map_length + 1);
		if (!array[i])
			exit_error("Malloc Error", data);
		ft_memset(array[i], '0', data->map_info.map_length - 1);
		array[i][data->map_info.map_length - 1] = '\n';
		array[i][data->map_info.map_length] = 0;
		i++;
	}
	return (array);
}

int	isvalid(char c, char visited)
{
	if (c == '1' || visited == '1')
		return (0);
	else
		return (1);
	return (0);
}

int	free_dfsmemory(t_data *data, char **visited, t_queue *head, t_pos *pos)
{
	t_queue	*tmp;
	int		i;

	i = -1;
	while (++i < data->map_info.map_heigth)
		free(visited[i]);
	free(visited);
	while (head)
	{
		tmp = head;
		head = tmp->next;
		free(tmp);
	}
	free(pos);
	return (1);
}
