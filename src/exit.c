/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:54:40 by erickbarros       #+#    #+#             */
/*   Updated: 2022/06/16 02:35:59 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_error(char *error_message)
{
	ft_printf("Error\n%s\nClosing Program\n", error_message);
	exit(0);
}

int	exit_clean(t_data *data)
{
	ft_printf("\nThanks for playing :)\n");
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}
