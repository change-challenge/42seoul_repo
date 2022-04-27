/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:20:02 by hchang            #+#    #+#             */
/*   Updated: 2022/04/27 23:52:02 by hojinjang        ###   ########.fr       */
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


#include <stdio.h>
char *get_next_line(int fd)
{
	static char s_back[OPEN_MAX];
	t_list 		*lst;
	ssize_t		rd;
	size_t		line_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// lst를 initialize 하기 
	if (*s_back)
		lst = ft_lstnew_str(s_back);
	


	// s_back이 있을 경우를 만들기
	// 
	
	
	
	
	
	
	










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