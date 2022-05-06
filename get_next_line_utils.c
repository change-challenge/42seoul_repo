/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:20:27 by hchang            #+#    #+#             */
/*   Updated: 2022/05/06 18:09:52 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_lstfclean(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	return (NULL);
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

size_t	*ft_strchr(const char *s, int c)
{
	int	idx;

	idx = 0;
	if (c == '\0' || s == NULL)
		return (0);
	while (s[idx])
	{
		if (s[idx] == (unsigned char)c)
			return (idx);
		idx++;
	}
	return (0);
}

t_list	*ft_lstnew_add_back(t_list **lst, void *content)
{
	t_list	*new;
	t_list	*tmp;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	if (!lst)
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
