/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 02:42:32 by egoncalv          #+#    #+#             */
/*   Updated: 2022/06/08 23:40:57 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;

	i = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] && len > 0)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && len > 0)
		{
			j++;
			len--;
		}
		if (needle[j] == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
