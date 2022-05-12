/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:20:02 by hchang            #+#    #+#             */
/*   Updated: 2022/05/12 18:52:21 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// 삭제할 헤더
#include <stdio.h>
#include <fcntl.h>


t_list*	read_line(int fd, t_list **t_back, ssize_t *rd)
{
	char		*tmp;

	tmp = (char *)malloc(BUFFER_SIZE + 1);
	*rd = read(fd, tmp, BUFFER_SIZE);
	if (*rd <= 0)
	{
		free(tmp);
		return (NULL);
	}
	tmp[*rd] = '\0';
	return (ft_lstnew_add_back(t_back, tmp));
}

// #1 : I need read return value (ssize_t)
// #2 : I need to know how long is String (consider EOF)

size_t	check_line(int fd, t_list **t_back, size_t *res_len)
{
	ssize_t rd;
	size_t	enter;
	size_t	len;
	t_list	*curr;

	curr = *t_back;
	while (1)
	{
		len = 0;
		if (curr)
		{
			enter = ft_strchr((curr)->content, '\n', &len);
			// 문제는 리턴에서 
			// '\n'값과 EOF를 구분해야한다. 
			// '\n'에는 거기까지의 enter를 더해야하고,
			// EOF는 마지막까지의 길이를 더해야한다. 
			// 1. 구분하는 기준과 2. 더하는 것의 분리가 필요.
			if (enter != (size_t)-1)			{
				*res_len += (enter + 1);
				return (rd);
			}
			*res_len += len;
		}
		curr = read_line(fd, t_back, &rd);
		if (!curr)
			return (rd);
	}
	return (rd);
}

char	*make_line(t_list **t_back, size_t res_len, char* res)
{
	char	*s_save;
	t_list	*t_clean;
	size_t	enter;
	size_t	tmp;

	// printf("========[t_back 리스트]=======\n");
	// while ((*t_back)->next == NULL)
	// 	printf("|%s|\n", (*t_back)->content);
	// printf("=======================\n");

	t_clean = *t_back;
	tmp = 0;
	res[0] = '\0';
	while (*t_back)
	{
		ft_strlcat(res, (*t_back)->content, res_len + 1);
		if ((*t_back)->next == NULL)
			s_save = (*t_back)->content;
		*t_back = (*t_back)->next;
	}
	// printf("res : |%s|\n", res);
	enter = ft_strchr(s_save, '\n', &tmp); // 마지막이라는 것을 확인? 어떤 식으로 ?
	if ((enter != (size_t)-1) && *(s_save + 1) != '\0')
		*t_back = ft_lstnew(ft_strdup(s_save + (enter + 1)));
	ft_lstfclean(&t_clean);

	// printf("========[출력 값]=======\n");
	//printf("|%s|\n", res);
	// printf("======================\n");

	return (res);	
}

char *get_next_line(int fd)
{
	char			*result;
	static t_list	*t_back;
	size_t			res_len;
	ssize_t			rread;

	res_len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rread = check_line(fd, &t_back, &res_len);
	if ((!rread && !res_len) || rread == -1)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (res_len + 1));
	if (!result)
		return (NULL);
	result[res_len] = '\0';
	return (make_line(&t_back, res_len, result));
}

// int	main()
// {
// 	int		fd;
// 	char	*line;
	
// 	fd = open("test.txt", O_RDONLY);
// 	while ((line = (get_next_line(fd))))
// 	{
// 		if (line == NULL)
// 			break;
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	printf("%s\n", line);
// 	free(line);
// }

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	printf("%s\n", line);
// 	free(line);
// 	close(fd);
// 	return (0);
// }

// first of all, it can read lines.
// what we have to do is "filtering"