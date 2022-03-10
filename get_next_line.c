/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:20:02 by hchang            #+#    #+#             */
/*   Updated: 2022/03/10 18:35:26 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// 삭제할 헤더
#include <stdio.h>
#include <fcntl.h>

char *make_str(size_t full_len, t_list* gnlst)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (full_len + 1));
	while (gnlst->next !=  NULL && full_len--)
	{
		while (*gnlst->str)
			*str++ = *gnlst->str++;
		gnlst = gnlst->next;
	}
	return (str);
}

void	put_str(char *gnl_str, char *tmp)
{
	while (*tmp)
		*gnl_str++ = *tmp++;
}

int	lstadd_front(t_list *gnlst, char *tmp)
{
	int	len;
	char *tmp_pct;

	tmp_pct = tmp;
	printf("tmp : %s\n", tmp);
	while (*tmp != '\0' || *tmp != '\n')
	{
		len++;
		tmp++;
	}
	while (gnlst->next == NULL)
	{
		gnlst->str = (char*)malloc(sizeof(char) * (len + 1));
		put_str(gnlst->str, tmp);
		gnlst = gnlst->next;
	}
	tmp = tmp_pct;
	return (len);
}

t_list*	make_linked_list(t_list *gnlst, char *back_up, size_t *f_len, int fd)
{
	char	*str;
	int		len;

	f_len = 0;
	if (back_up)
	{
		len = lstadd_front(gnlst, back_up);
		f_len += len;
	}
	printf("fd : %d\n", fd);
	while (read(fd, str, 5) != -1)
	{
		printf("HERE\n");
		len = lstadd_front(gnlst, str);
		f_len += len;
	}
	return (gnlst);
}

char *get_next_line(int fd)
{
	static char	*back_up;
	t_list		*gnlst;
	size_t		full_len;

	if (fd < 0)
		return (NULL);
	printf("fd : %d\n", fd);
	gnlst = make_linked_list(gnlst, back_up, &full_len, fd);
	return (make_str(full_len, gnlst));

	// char *str;
	// printf("address : %p || str : %s\n", &str, str);
	// read(fd, str, 5);
	// printf("address : %p || str : %s\n", &str, str);
	// read(fd, str, 5);
	// printf("address : %p || str : %s\n", &str, str);
	// return (str);
}

int main() 
{ 
	int		fd;
	char*	tmp;

	fd = open("./a.txt", O_RDONLY);
	printf("fd : %d\n", fd);
	printf("return : |%s|\n", get_next_line(fd));
	close(fd);
}