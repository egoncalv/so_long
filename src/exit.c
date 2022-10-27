/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:54:40 by erickbarros       #+#    #+#             */
/*   Updated: 2022/10/26 17:51:25 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_error(char *error_message, t_data *data)
{
	ft_printf("Error\n%s\nClosing Program\n", error_message);
	mlx_destroy_window(data->mlx, data->win);
	free(data);
	exit(0);
}

int	exit_clean(t_data *data)
{
	ft_printf("\nThanks for playing :) %d\n", data->steps);
	mlx_destroy_window(data->mlx, data->win);
	free(data);
	exit(0);
}
