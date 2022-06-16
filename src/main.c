/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:10:32 by egoncalv          #+#    #+#             */
/*   Updated: 2022/06/16 01:31:11 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_data		data;

	check_extension(argv[1], argc);
	parse_maps(argv[1], &data);
	init_mlx(&data);
	return (0);
}
