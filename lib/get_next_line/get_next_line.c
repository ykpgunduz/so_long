/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagunduz <yagunduz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:29:11 by yagunduz          #+#    #+#             */
/*   Updated: 2026/01/14 20:17:41 by yagunduz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*update_remainder(char *remainder)
{
	char	*new_remainder;
	char	*newline_ptr;
	size_t	start;

	newline_ptr = ft_strchr(remainder, '\n');
	if (!newline_ptr)
	{
		free(remainder);
		return (NULL);
	}
	start = (newline_ptr - remainder) + 1;
	if (remainder[start] == '\0')
	{
		free(remainder);
		return (NULL);
	}
	new_remainder = ft_substr(remainder, start, ft_strlen(remainder) - start);
	free(remainder);
	return (new_remainder);
}

static char	*extract_line(char *remainder)
{
	char	*newline_ptr;
	char	*line;
	size_t	len;

	if (!remainder || remainder[0] == '\0')
		return (NULL);
	newline_ptr = ft_strchr(remainder, '\n');
	if (newline_ptr)
		len = (newline_ptr - remainder) + 1;
	else
		len = ft_strlen(remainder);
	line = ft_substr(remainder, 0, len);
	return (line);
}

static char	*read_and_remainder(int fd, char *remainder)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && (!remainder || !ft_strchr(remainder, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(remainder);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin_and_free(remainder, buffer);
		if (!remainder)
			break ;
	}
	free(buffer);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (remainder)
		{
			free(remainder);
			remainder = NULL;
		}
		return (NULL);
	}
	remainder = read_and_remainder(fd, remainder);
	if (!remainder)
		return (NULL);
	line = extract_line(remainder);
	remainder = update_remainder(remainder);
	return (line);
}
