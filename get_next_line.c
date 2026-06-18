/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 10:47:48 by crubio-p          #+#    #+#             */
/*   Updated: 2026/06/18 10:56:00 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_joined_buffer(char *buffer, int fd)
{
	char	temp[BUFFER_SIZE + 1];
	long	i;
	
	if(buffer && ft_stchr(buffer, '\n'))
		return (buffer);
	ft_bzero(temp, BUFFER_SIZE + 1);
	while (!ft_strchr(temp, '\n'))
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i < 0 || (!i && !buffer))
		{
			free(buffer);
			return (NULL);
		}
		temp[i] = '\0';
		if (!buffer)
			buffer = ft_strdup(temp);
		else
			buffer = ft_strjoin(buffer, temp);
		if (!buffer)
			return (NULL);
	}
	return (buffer);
	
}

/**
 * Llamar a la función get_next_line de manera repetida (por ejemplo, usando un 
 * bucle) permitirá leer el contenido del archivo hacia el que apunta el
 * descriptor de archivo, línea a línea, hasta el final.
 * 
 * Deberá devolver la línea que se acaba de leer.
 * 
 * Si no hay nada más que leer o si ha ocurrido un error, deberá devolver NULL.
 * 
 * Asegurarse de que se comporta adecuadamente cuando lea de un archivo y cuando
 * lea de 'stdin'.
 * 
 * La línea devuelta debe terminar con \n, excepto si se ha llegado al final del
 * archivo y éste no termina con una \n.
 * 
 * 
 */
char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*ret_line;
	static char		*residue;
	int				i;
		
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = get_joined_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	ret_line = ft_substr(buffer, 0, i);
	residue = ft_substr(buffer, i, ft_strlen(buffer) - i);
	free(buffer);
	buffer = residue;
	return (ret_line);	
}
