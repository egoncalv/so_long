/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:10:32 by egoncalv          #+#    #+#             */
/*   Updated: 2022/11/09 12:50:47 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Creates a struct that will hold our game's informations,
//and calls the functions responsible for checking for errors,
//parsing maps and rendering the game

int	main(int argc, char *argv[])
{
	t_data		data;

	data.argv = argv[1];
	check_extension(argv[1], argc, &data);
	parse_maps(&data);
	init_mlx(&data);
	return (0);
}
