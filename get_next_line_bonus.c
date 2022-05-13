/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:20:02 by hchang            #+#    #+#             */
/*   Updated: 2022/05/13 10:16:07 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strchr(const char *s, int c, size_t *len)
{
	int	idx;

	idx = 0;
	while (s[*len])
		(*len)++;
	while (s[idx])
	{
		if (s[idx] == (unsigned char)c)
			return (idx);
		idx++;
	}
	return (-1);
}

t_list	*read_line(int fd, t_list **t_back, ssize_t *rd)
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

size_t	check_line(int fd, t_list **t_back, size_t *res_len)
{
	ssize_t	rd;
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
			if (enter != (size_t) - 1)
			{
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

char	*make_line(t_list **t_back, size_t res_len, char *res)
{
	char	*s_save;
	t_list	*t_clean;
	size_t	enter;
	size_t	tmp;

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
	enter = ft_strchr(s_save, '\n', &tmp);
	if ((enter != (size_t)-1) && *(s_save + enter + 1) != '\0')
		*t_back = ft_lstnew(ft_strdup(s_save + (enter + 1)));
	ft_lstfclean(&t_clean);
	return (res);
}

char	*get_next_line(int fd)
{
	char			*result;
	static t_list	*t_back[FD_MAX];
	size_t			res_len;
	ssize_t			rread;

	res_len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || FD_MAX <= 0 || fd >= FD_MAX)
		return (NULL);
	rread = check_line(fd, &t_back[fd], &res_len);
	if ((!rread && !res_len) || rread == -1)
		return ((char *)ft_lstfclean(&t_back[fd]));
	result = (char *)malloc(sizeof(char) * (res_len + 1));
	if (!result)
		return (NULL);
	result[res_len] = '\0';
	return (make_line(&t_back[fd], res_len, result));
}
