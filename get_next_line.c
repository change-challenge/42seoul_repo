/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:20:02 by hchang            #+#    #+#             */
/*   Updated: 2022/05/05 12:37:22 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// 삭제할 헤더
#include <stdio.h>
#include <fcntl.h>

t_list	*ft_lstadd_back_last(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return (NULL);
	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

t_list	*ft_lstnew_str(char *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}


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

static ssize_t	line_check_len(int fd, t_list **lst, size_t *len)
{
	char			*pos;
	char			*buf;
	t_list			*tmp;
	ssize_t			rd;
	size_t			content_len;

	// 일차적으로 할 것은 재귀문을 while로 바꾸는 것
	if (*lst)
	{
		pos = ft_strlen_chr_init((*lst)->content, '\n', &content_len, 0);
		if (pos)
		{
			*len += (pos - (*lst)->content) + 1;
			return (0);
		}
		(*len) += content_len;
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	rd = read(fd, buf, BUFFER_SIZE);
	if (rd <= 0)
	{
		free(buf);
		return (NULL);
	}
	buf[rd] = '\0';
	tmp = ft_lstadd_back_last(lst, ft_lstnew_str(buf))
	if (tmp)
		rd = line_check_len(fd, &tmp, len);


	return (rd);
}

#include <stdio.h>
char *get_next_line(int fd)
{
	static char *s_back;
	char 		*res;
	char		*tmp;
	size_t		res_len;
	ssize_t		rread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rread = line_check_len(fd, &s_back, &res_len);

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