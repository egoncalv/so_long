/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:54:40 by erickbarros       #+#    #+#             */
/*   Updated: 2022/10/28 15:14:38 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	exit_error(char *error_message, t_data *data)
{
	ft_printf("Error\n%s\nClosing Program\n", error_message);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	/*while (*data->map)
	{
		free(*data->map);
		data->map++;
	}
	free(data->map);*/
	exit(0);
}

int	exit_clean(t_data *data)
{
	ft_printf("\nThanks for playing :)\n");
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
/*	while (*data->map)
	{
		free(*data->map);
		data->map++;
	}*/
	//free(data->map);
	exit(0);
}
