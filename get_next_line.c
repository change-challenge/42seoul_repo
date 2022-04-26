/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:20:02 by hchang            #+#    #+#             */
/*   Updated: 2022/04/26 20:05:23 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// 삭제할 헤더
#include <stdio.h>
#include <fcntl.h>

// char *make_str(size_t full_len, t_list* gnlst)
// {
// 	char *str;

// 	str = (char *)malloc(sizeof(char) * (full_len + 1));
// 	while (gnlst->next !=  NULL && full_len--)
// 	{
// 		while (*gnlst->str)
// 			*str++ = *gnlst->str++;
// 		gnlst = gnlst->next;
// 	}
// 	return (str);
// }

// void	put_str(char *gnl_str, char *tmp)
// {
// 	while (*tmp)
// 		*gnl_str++ = *tmp++;
// }

int	lstadd_front(t_list *gnlst, char *tmp, char *back_up)
{
	int	len;
	int s_len;

	len = 0;
	while (*tmp != '\0' || *tmp != '\n')
		len++;
	s_len = BUFFER_SIZE - len;
	while (!(gnlst->next == NULL))
		gnlst = gnlst->next;
	gnlst->str = (char*)malloc(sizeof(char) * (len + 1));
	if (gnlst->str == NULL)
		return (0);
	while (len--)
		*gnlst->str++ = *tmp++;
	if (s_len)
	{
		while (s_len--)
			*back_up++ = *tmp++;
	}
	return (len);
}

int	ft_strchr(const char *str, int c)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	if (str == NULL)
		return (FAIL);
	while (str[idx])
	{
		if (str[idx] == (unsigned char)c)
			return (FAIL);
		idx++;
	}
	return (SUCCESS);
}

void println(t_list *gnlst)
{
	while (gnlst->next)
	{
		printf("%s\n", gnlst->str);
		gnlst = gnlst->next;
	}
}

#include <stdio.h>
char *get_next_line(int fd)
{
	static char	*s_backup;
	char		tmp[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	while (read(fd, tmp, BUFFER_SIZE) > 0)
	{		
		printf("this is it! : %s\n", tmp);	
	}
	return (NULL);
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