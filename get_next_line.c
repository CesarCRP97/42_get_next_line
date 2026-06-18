/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 10:47:48 by crubio-p          #+#    #+#             */
/*   Updated: 2026/06/18 16:17:52 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Make line

// Join buffer and free previous buffer

// Free all

char	*get_joined_buffer(char *buffer, int fd)
{
	char	*temp;
	long	i;
	
	if(buffer && ft_stchr(buffer, '\n'))
		return (buffer);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while (!ft_strchr(temp, '\n'))
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i < 0 || (!i && !buffer))
		{
			free(buffer);
			return (NULL);
		}
		if (!buffer)
			buffer = ft_calloc(1, 1);
		buffer = ft_strjoin(buffer, temp);
		if (!buffer)
			return (NULL);
	}
	return (buffer);
	
}

/// @brief Reads a line from a file descriptor and returns it as a string.
/// @param fd file descriptor to read from.
/// @return The next line from the file descriptor, or NULL if there is an error
char	*get_next_line(int fd)
{
	static char		*residue;
	char			*temp;
	char			*next_line;
	int				i;
		
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	temp = get_joined_buffer(residue, fd);
	if (!temp)
		return (NULL);
	i = 0;	
	while (temp[i] != '\n' && temp[i])
		i++;
	if (temp[i] == '\n')
		i++;
	next_line = ft_substr(temp, 0, i - 1);
	residue = ft_substr(temp, i, ft_strlen(temp) - i);
	free(temp);
	temp = NULL;
	return (next_line);	
}
