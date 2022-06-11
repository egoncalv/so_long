/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:10:32 by egoncalv          #+#    #+#             */
/*   Updated: 2022/06/11 02:44:32 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_list		*map;
	t_map		map_info;

	map = 0;
	check_extension(argv[1], argc);
	map = parse_maps(argv[1], map, &map_info);
	init_mlx(map, &map_info);
	return (0);
}
