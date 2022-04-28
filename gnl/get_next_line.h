/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:35:42 by egoncalv          #+#    #+#             */
/*   Updated: 2022/04/28 06:37:07 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_stringlen(const char *s);
char	*ft_stringchr(const char *s, int c);
char	*ft_stringjoin(char *s1, char *s2);
char	*ft_strldup(char *s1, int size);
char	*ft_read_set(int fd, char *state);
char	*ft_line(char *state);
char	*ft_state(char *state);

#endif
