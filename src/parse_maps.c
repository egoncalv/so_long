/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 07:34:07 by egoncalv          #+#    #+#             */
/*   Updated: 2022/04/28 07:45:15 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	parse_maps(char	*argv)
{
	t_map	map;
	
	map.fd = open(argv, O_RDONLY);
	return (1);
}
