/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:43:06 by egoncalv          #+#    #+#             */
/*   Updated: 2022/10/27 13:41:37 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_queue	*create_queue(t_pos *pos, t_data *data, int add_y, int add_x)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		exit_error("Malloc Error", data);
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
