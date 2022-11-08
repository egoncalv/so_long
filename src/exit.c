/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:54:40 by erickbarros       #+#    #+#             */
/*   Updated: 2022/11/08 18:50:58 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	exit_error(char *error_message, t_data *data)
{
	int	i;

	ft_printf("Error\n%s\nClosing Program\n", error_message);
	if (data->mlx && data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->mlx && data->win)
	{	
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
	}
	i = -1;
	while (++i < data->map_info.map_heigth)
		free(data->map[i]);
	free(data->map);
	free(data->mlx);
	exit(0);
}

int	exit_clean(t_data *data)
{
	int	i;

	ft_printf("\nThanks for playing :)\n");
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	i = -1;
	while (++i < data->map_info.map_heigth)
		free(data->map[i]);
	free(data->map);
	free(data->mlx);
	exit(0);
}
