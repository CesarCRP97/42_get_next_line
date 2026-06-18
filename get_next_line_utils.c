/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 10:48:05 by crubio-p          #+#    #+#             */
/*   Updated: 2026/06/18 15:52:12 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *string)
{
	size_t	len;

	len = 0;
	while (string[len])
	{
		len++;
	}
	return (len);
}

/// @brief Searches for the first occurrence of the character ’c’ (an unsigned 
/// char) in the string pointed to by ’s’.
/// @param s string to be searched.
/// @param c character to be searched for.
/// @return A pointer to the first occurrence of the character c in s
char	*ft_strchr(const char *s, int c)
{
		int		i;
		char	c_to_char;

		i = 0;
		c_to_char = (char)c;
		while (s[i] != '\0')
		{
				if (s[i] == c_to_char)
						return ((char *)&s[i]);
				i++;
		}
		if (s[i] == '\0' && c_to_char == '\0')
				return ((char *)&s[i]);
		return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	int		n;
	int		i;

	if (nmemb != 0 && size > (size_t) - 1 / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	n = size * nmemb;
	while (i < n)
	{
		((unsigned char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}

/// @brief Allocates (with malloc(3)) and returns a substring from the string 
/// ’s’. The substring begins at index ’start’ and is of maximum size ’len’.
/// @param s String from which to create the substring.
/// @param start Index of the first character of the substring in the string ’s’
/// @param len Maximum length of the substring
/// @return Pointer to the new substring, or NULL if allocation fails
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_calloc(1, 1));
	if (len > slen - start)
		len = slen - start;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	return (str);
}
