/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:00:54 by egoncalv          #+#    #+#             */
/*   Updated: 2022/10/25 16:43:08 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	find_path(t_data *data)
{
	char	**visited;
	t_queue *queue;
	t_pos	*pos;

	pos = 0;
	visited = 0;
	visited = create_array(visited, data);
	pos->y = data->player.y;
	pos->x = data->player.x;
	queue = create_queue(pos, 0, 0);
	while (queue)
	{
		if (isvalid(data->map[queue->y + 1][queue->x]))
			ft_queueadd_back(&queue, create_queue(pos, 1, 0));
		if (isvalid(data->map[queue->y - 1][queue->x]))
			ft_queueadd_back(&queue, create_queue(pos, -1, 0));
		if (isvalid(data->map[queue->y][queue->x + 1]))
			ft_queueadd_back(&queue, create_queue(pos, 0, 1));
		if (isvalid(data->map[queue->y][queue->x - 1]))
			ft_queueadd_back(&queue, create_queue(pos, 0, -1));
		visited[queue->y][queue->x] = '1';
		queue = queue->next;
	}
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


int	isvalid(char c)
{
	if (c == '1' || c =='E')
		return (0);
	else
		return (1);
}
