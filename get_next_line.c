/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:20:02 by hchang            #+#    #+#             */
/*   Updated: 2022/03/03 21:44:20 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// 삭제할 헤더
#include <stdio.h>
#include <fcntl.h>

int	check_str_null_eof(char *tmp)
{
	while (*tmp++)
	{
		if (*tmp == '\0' || *tmp == '\n')
			return (ERROR);
	}
	return (SUCCESS);
}

int	lstadd_front(t_list *gnl_list, char *tmp)
{
	int	len;

	while (*tmp == '\0' || *tmp == '\n')
	{
		len++;
		tmp++;
	}
	while (gnl_list->next == NULL)
	{
		gnl_list->str = (char*)malloc(sizeof(char) * (len + 1));
		gnl_list = gnl_list->next;
	}
	return (len);
}

char *get_next_line(int fd)
{
	static char	*back_up;
	t_list		*gnl_list;
	size_t		len;
	char		*tmp;
	char 		*result;


// 오히려 마지막에 result malloc과 input 

}


int main() 
{ 
	char 	str[BUFFER_SIZE]; 
	int		fd;
	int		read_len;

	
	fd = open("./a.txt", O_RDONLY);
	// read_len = read(fd, str, BUFFER_SIZE);
	// str[BUFFER_SIZE] = '\0';
	// printf("|%s|\n", str);


	printf("|%d|\n", read_len);
	close(fd);
}