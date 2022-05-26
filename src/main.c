/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:10:32 by egoncalv          #+#    #+#             */
/*   Updated: 2022/05/20 19:16:42 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_printf("You need to pass at least one map as argument!");
		return (0);	
	}
	else if (parse_maps(argv[1]) == 0)
	{
		ft_printf("This map is invalid");
		return (0);
	}
	else
		parse_maps(argv[1]);
	return (0);
}
