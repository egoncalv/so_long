/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:33:52 by egoncalv          #+#    #+#             */
/*   Updated: 2022/04/28 06:34:33 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_set(int fd, char *state)
{
	char		*buffer;
	int			read_return;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_return = 1;
	while (read_return != 0 && !ft_stringchr(state, '\n'))
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_return] = 0;
		state = ft_stringjoin(state, buffer);
	}
	free(buffer);
	return (state);
}

char	*ft_line(char *state)
{
	int		line_size;
	char	*line;

	line_size = 0;
	if (!state)
		return (NULL);
	if (state[line_size] == '\n')
	{
		line = malloc(sizeof(char) * 2);
		if (!line)
			return (NULL);
		line[0] = '\n';
		line[1] = 0;
		return (line);
	}
	while (state[line_size] && state[line_size] != '\n')
		line_size++;
	line = ft_strldup(state, line_size);
	return (line);
}

char	*ft_state(char *state)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (state[i] && state[i] != '\n')
		i++;
	if (!state[i])
	{
		free(state);
		return (NULL);
	}
	str = malloc(sizeof(char) * ft_stringlen(state) - i + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (state[i])
	{
		str[j++] = state[i++];
	}
	str[j] = 0;
	free(state);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*state;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	state = ft_read_set(fd, state);
	if (!state)
		return (NULL);
	line = ft_line(state);
	state = ft_state(state);
	return (line);
}
