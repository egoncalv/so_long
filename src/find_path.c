/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:00:54 by egoncalv          #+#    #+#             */
/*   Updated: 2022/10/26 15:59:33 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	find_path(t_data *data, int goal_y, int goal_x)
{
	char	**visited;
	t_queue *queue;
	t_queue *tmp;;
	t_pos	*pos;


	pos = malloc(sizeof(t_pos *));
	visited = 0;
	visited = create_array(visited, data);
	pos->y = data->player.y;
	pos->x = data->player.x;
	queue = create_queue(pos, 0, 0);
	while (queue)
	{
		visited[queue->y][queue->x] = '1';
		pos->y = queue->y;
		pos->x = queue->x;
		if (pos->y == goal_y && pos->x == goal_x)
		{
			free(visited);
			free(queue);
			return (1);
		}
		if (isvalid(data->map[queue->y + 1][queue->x], visited[queue->y + 1][queue->x]))
			ft_queueadd_back(&queue, create_queue(pos, 1, 0));
		if (isvalid(data->map[queue->y - 1][queue->x], visited[queue->y - 1][queue->x]))
			ft_queueadd_back(&queue, create_queue(pos, -1, 0));
		if (isvalid(data->map[queue->y][queue->x + 1], visited[queue->y][queue->x + 1]))
			ft_queueadd_back(&queue, create_queue(pos, 0, 1));
		if (isvalid(data->map[queue->y][queue->x - 1], visited[queue->y][queue->x - 1]))
			ft_queueadd_back(&queue, create_queue(pos, 0, -1));
		tmp = queue->next;
		free(queue);
		queue = tmp;	
	}
	free(visited);
	return (0);
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

//create queue using linked lists
t_queue	*create_queue(t_pos *pos, int add_y, int add_x)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		exit_error("Malloc Error");
	queue->y = pos->y + add_y;
	queue->x = pos->x + add_x;
	queue->next = NULL;
	return (queue);
}

void	ft_queueadd_back(t_queue **queue, t_queue *new)
{
	t_queue	*last;

	if (queue)
	{
		if (*queue == NULL)
			*queue = new;
		else
		{
			last = ft_queuelast(*(queue));
			last->next = new;
		}
	}
}

t_queue	*ft_queuelast(t_queue *queue)
{
	if (!queue)
		return (0);
	while (queue)
	{
		if (queue->next == NULL)
			return (queue);
		queue = queue->next;
	}
	return (queue);
}


int	isvalid(char c, char visited)
{
	if (c == '1' || visited == '1')
		return (0);
	else
		return (1);
}
