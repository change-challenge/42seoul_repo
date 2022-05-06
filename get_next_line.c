/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:20:02 by hchang            #+#    #+#             */
/*   Updated: 2022/05/06 17:56:28 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// 삭제할 헤더
#include <stdio.h>
#include <fcntl.h>


t_list*	read_line(int fd, t_list **t_back)
{
	ssize_t		rd;
	char		*tmp;

	tmp = (char *)malloc(BUFFER_SIZE + 1);
	rd = read(fd, tmp, BUFFER_SIZE);
	if (rd <= 0)
	{
		free(tmp);
		return (NULL);
	}
	tmp[rd] = '\0';
	return (ft_lstnew_add_back(&t_back, tmp));
}

// #1 : I need read return value (ssize_t)
// #2 : I need to know how long is String (consider EOF)

size_t	check_line(int fd, t_list **t_back, size_t *res_len)
{
	ssize_t rd;
	size_t	pos;

	while (1)
	{
		pos = ft_strchr(*t_back, '\n');
		if (pos)
		{
			res_len += pos;
			break;
		}
		res_len += BUFFER_SIZE;
	}
	
}

char *get_next_line(int fd)
{
	static t_list	*t_back;
	size_t			res_len;
	ssize_t			rread;

	res_len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rread = check_line(fd, &t_back, &res_len);

}





int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	close(fd);
	return (0);
}

// first of all, it can read lines.
// what we have to do is "filtering"