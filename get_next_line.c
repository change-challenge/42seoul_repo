/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:20:02 by hchang            #+#    #+#             */
/*   Updated: 2022/04/29 17:59:32 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// 삭제할 헤더
#include <stdio.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s)
{
	unsigned int	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	src_len;

	idx = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize != 0)
	{
		while (idx < (dstsize - 1) && src[idx])
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = '\0';
	}
	return (src_len);
}

char	*ft_strchr(const char *s, int c)
{
	int	idx;
	int	s_len;

	idx = 0;
	s_len = ft_strlen(s);
	if (c == '\0' || s == NULL)
		return ((char *)s + s_len);
	while (s[idx])
	{
		if (s[idx] == (unsigned char)c)
			return ((char *)s + idx);
		idx++;
	}
	return (0);
}

char *first_move(char *res, char *s_back)
{
	res = malloc(sizeof(s_back) + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s_back, ft_strlen(s_back));
	res[ft_strlen(s_back)] = 0;
	free(res);
	
	return (res);
}


char *make_line(char *res, char **s_back, int fd)
{
	char *tmp;

	tmp = malloc(sizeof(BUFFER_SIZE));
	if (tmp == NULL)
		return (NULL);
}

#include <stdio.h>
char *get_next_line(int fd)
{
	static char *s_back;
	char 		*res;
	ssize_t		rread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (*s_back || !ft_strchr(s_back, '\n'))
		res = first_move(res, s_back);
	return (make_line(res, &s_back, fd));
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