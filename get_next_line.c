/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 10:47:48 by crubio-p          #+#    #+#             */
/*   Updated: 2026/06/21 18:47:36 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// @brief Standardized function to search the positions of the first '\n' 
/// beginning in 'i'.
/// @param str The string to search in.
/// @param i The first position where to look.
/// @return Position + 1 where the '\n' has been found.
size_t	find_line_ending(char *str, size_t i)
{
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

/// @brief Given a string, creates a copy of everything but the first line of 
/// the string. So first it detects where the first line ends, and copies from
/// there.
/// @param str String given
/// @return A copy of the first line of 'str'
char	*get_string(char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!str || str[0] == '\0')
		return (free(str), NULL);
	i = find_line_ending(str, 0);
	new_str = (char *)ft_calloc(sizeof(char), (ft_strlen(str) - i + 1));
	if (!new_str)
		return (free(new_str), NULL);
	j = 0;
	while (str[i])
		new_str[j++] = str[i++];
	return (free(str), new_str);
}

/// @brief Reads the first line from the 'str'.
/// @param str string to search in.
/// @return A copy of the first line of the 'str'.
char	*read_the_line(char *str)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	i = find_line_ending(str, i);
	line = (char *)ft_calloc(sizeof(char), i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	return (line);
}

char	*free_and_null(char *buff1, char *buff2)
{
	free(buff1);
	free(buff2);
	buff2 = NULL;
	return (0);
}

/// @brief Reads a line until the '\n'.
/// @param fd file descriptor from where to read.
/// @return The next line of fd.
char	*get_next_line(int fd)
{
	static char	*read_buffer;
	char		*read_content;
	int			read_bytes;

	read_bytes = 1;
	if ((fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX))
		return (free(read_buffer), NULL);
	read_content = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!read_content)
		return (free(read_buffer), NULL);
	while (!(ft_strchr(read_buffer, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, read_content, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			read_buffer = free_and_null(read_content, read_buffer);
			return (NULL);
		}
		read_content[read_bytes] = '\0';
		read_buffer = ft_strjoin(read_buffer, read_content);
	}
	free(read_content);
	read_content = read_the_line(read_buffer);
	read_buffer = get_string(read_buffer);
	return (read_content);
}
