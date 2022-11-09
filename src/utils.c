/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:57:20 by egoncalv          #+#    #+#             */
/*   Updated: 2022/11/09 17:56:05 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_lines(char *argv)
{
	int		count;
	int		fd;
	char	*tmp;

	count = 0;
	fd = open (argv, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		count++;
		tmp = get_next_line(fd);
	}
	close (fd);
	return (count);
}

void	check_extension(char *file, int argc, t_data *data)
{
	char	*extension;

	if (argc < 2)
		exit_error("You must pass one valid map as argument!", data);
	extension = ft_strrchr(file, '.');
	if (!extension || ft_strncmp(extension, ".ber", 4) != 0)
		exit_error("The map needs a .ber extension!", data);
}

void	set_map(t_data *data)
{
	data->map_info.wall = mlx_xpm_file_to_image(data->mlx, WALL,
			&data->img_width, &data->img_heigth);
	data->map_info.player = mlx_xpm_file_to_image(data->mlx,
			PLAYER_LEFT, &data->img_width, &data->img_heigth);
	data->map_info.empty = mlx_xpm_file_to_image(data->mlx, EMPTY,
			&data->img_width, &data->img_heigth);
	data->map_info.collect = mlx_xpm_file_to_image(data->mlx,
			COLLECT, &data->img_width, &data->img_heigth);
	data->map_info.exit = mlx_xpm_file_to_image(data->mlx, EXIT,
			&data->img_width, &data->img_heigth);
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

void	check_chars(char c, t_data *data)
{
	if (c != 'P' && c != 'E' && c != '0' && c != '1' && c != 'C')
		exit_error("Invalid Char found in the map", data);
}
