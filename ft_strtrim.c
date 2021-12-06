/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 01:26:30 by hojinjang         #+#    #+#             */
/*   Updated: 2021/12/06 00:38:27 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*new_str;
	size_t			front;
	size_t			rear;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	front = 0;
	rear = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[front]) && s1[front])
		front++;
	while (ft_strchr(set, s1[rear]) && s1[rear] && rear + 1 > front)
		rear--;
	new_str = malloc(sizeof(char) * (rear - front + 2));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, &s1[front], rear - front + 2);
	return (new_str);
}
