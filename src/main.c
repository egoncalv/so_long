/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:10:32 by egoncalv          #+#    #+#             */
/*   Updated: 2022/11/09 17:59:17 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Creates a struct that will hold our game's informations,
//and calls the functions responsible for checking for errors,
//parsing maps and rendering the game

int	main(int argc, char *argv[])
{
	t_data		data;

	data.mlx = 0;
	data.map = 0;

	if (argc < 2)
		exit_error("You must pass one valid map as argument!", &data);
	
	data.map_file_path = argv[1];
	check_file_exists(data.map_file_path, &data);
	check_file_extension(data.map_file_path, &data);
	parse_maps(&data);
	init_mlx(&data);

	return (0);
}
