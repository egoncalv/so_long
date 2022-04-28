/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:35:11 by egoncalv          #+#    #+#             */
/*   Updated: 2022/04/28 06:37:21 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_stringlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strldup(char *s1, int size)
{
	char	*str;
	int		i;

	if (size < 1 || !s1)
		return (NULL);
	str = malloc((sizeof(char) * size) + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] && i < size)
	{
		str[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_stringchr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (char)c;
	i = 0;
	if (!s)
		return (0);
	if (c == 0)
		return ((char *)&s[ft_stringlen(s)]);
	while (s[i])
	{
		if (ch == s[i])
			return ((char *)s + i);
		i++;
	}
	return (0);
}

char	*ft_stringjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_stringlen(s1) + ft_stringlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_stringlen(s1) + ft_stringlen(s2)] = '\0';
	free(s1);
	return (str);
}
