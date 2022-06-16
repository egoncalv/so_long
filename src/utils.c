/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:57:20 by egoncalv          #+#    #+#             */
/*   Updated: 2022/06/16 06:57:07 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_lines(char *argv)
{
	int		count;
	int		fd;

	count = 0;
	fd = open (argv, O_RDONLY);
	while (get_next_line(fd))
		count++;
	close (fd);
	return (count);
}

void	check_extension(char *file, int argc)
{
	char	*extension;

	if (argc < 2)
		exit_error("You must pass one valid map as argument!");
	extension = ft_strrchr(file, '.');
	if (!extension || ft_strncmp(extension, ".ber", 4) != 0)
		exit_error("The map needs a .ber extension!");
}

void	set_map(t_data *data)
{
	data->map_info.map_length = ft_strlen(data->map[0]);
	data->map_info.map_heigth = count_lines(data->argv);
	data->map_info.wall = "./assets/wall.xpm";
	data->map_info.player = "./assets/player.xpm";
	data->map_info.empty = "./assets/wood.xpm";
	data->map_info.collect = "./assets/collectible.xpm";
	data->map_info.exit = "./assets/door.xpm";
}

void	set_player_position(t_data *data, int x, int y, char element)
{
	if (element == 'P')
	{
		data->player.quantity += 1;
		data->player.x = x;
		data->player.y = y;
	}
}
