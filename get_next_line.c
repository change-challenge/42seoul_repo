/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:20:02 by hchang            #+#    #+#             */
/*   Updated: 2022/05/04 21:42:16 by hchang           ###   ########.fr       */
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




void	check_static(char **s_back, char **res, size_t *len)
{
	
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
	if (*s_back)
		check_static(&s_back, &res, &res_len);



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