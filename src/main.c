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
	int			fd;

	data.mlx = 0;
	data.map = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_error("The map does not exist", &data);
	close (fd);
	check_extension(argv[1], argc, &data);
	data.argv = argv[1];
	parse_maps(&data);
	init_mlx(&data);
	return (0);
}
