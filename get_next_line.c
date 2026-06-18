/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 10:47:48 by crubio-p          #+#    #+#             */
/*   Updated: 2026/06/18 09:30:04 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*residue;
	char		*line;

	if (fd < 0)
		return (NULL);
	//Crear line.
	//Si hay algo guardado en residue, añadirlo a la line.
	//Leer hasta encontrar \n o \0.
	//Crear substring hasta newLine.
	//Guardar lo demás en residue.
}
