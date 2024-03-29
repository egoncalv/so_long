/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:54:40 by erickbarros       #+#    #+#             */
/*   Updated: 2022/11/09 18:02:23 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	exit_error(char *error_message, t_data *data)
{
	int	i;

	ft_printf("Error\n%s\nClosing Program\n", error_message);
	destroy_images(data);
	if (data->mlx && data->win)
	{	
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
	}
	i = -1;
	if (data->map)
	{
		while (++i < data->map_info.map_heigth && data->map[i])
			free(data->map[i]);
		free(data->map);
	}
	if (data->mlx)
		free(data->mlx);
	exit(0);
}

int	exit_clean(t_data *data)
{
	int	i;

	ft_printf("\nThanks for playing :)\n");
	destroy_images(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	i = -1;
	while (++i < data->map_info.map_heigth && data->map[i])
		free(data->map[i]);
	free(data->map);
	free(data->mlx);
	exit(0);
}

void	destroy_images(t_data *data)
{
	if (data->mlx)
	{
		mlx_destroy_image(data->mlx, data->map_info.empty);
		mlx_destroy_image(data->mlx, data->map_info.player);
		mlx_destroy_image(data->mlx, data->map_info.collect);
		mlx_destroy_image(data->mlx, data->map_info.exit);
		mlx_destroy_image(data->mlx, data->map_info.wall);
	}
}
