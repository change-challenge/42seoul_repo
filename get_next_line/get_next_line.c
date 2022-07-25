/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:13:00 by kyhan             #+#    #+#             */
/*   Updated: 2022/07/25 14:26:54 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		index;

	index = 0;
	if (!buffer[index])
		return (NULL);
	while (buffer[index] != '\0' && buffer[index] != '\n')
		index++;
	line = malloc(sizeof(char) * (index + 2));
	if (line == 0)
		return (0);
	index = 0;
	while (buffer[index] != '\0' && buffer[index] != '\n')
	{
		line[index] = buffer[index];
		index++;
	}
	if (buffer[index] == '\n')
	{
		line[index] = buffer[index];
		index++;
	}
	line[index] = '\0';
	return (line);
}

char	*ft_save(char *buffer)
{
	int		i;
	int		j;
	char	*backup;

	i = 0;
	j = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (0);
	}
	backup = malloc(sizeof(char) * (ft_strlen_g(buffer) - i + 1));
	if (backup == 0)
		return (0);
	i++;
	while (buffer[i] != '\0')
		backup[j++] = buffer[i++];
	backup[j] = '\0';
	free(buffer);
	return (backup);
}

char	*ft_read(int fd, char *buffer)
{
	char	*buf;
	int		return_value;

	return_value = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == 0)
		return (0);
	while (!ft_strchr_g(buffer, '\n') && return_value != 0)
	{
		return_value = read(fd, buf, BUFFER_SIZE);
		if (return_value == -1)
		{
			free(buf);
			return (0);
		}
		buf[return_value] = '\0';
		buffer = ft_strjoin_g(buffer, buf);
	}
	free(buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_read(fd, buffer);
	if (buffer == 0)
		return (0);
	line = ft_get_line(buffer);
	buffer = ft_save(buffer);
	return (line);
}
