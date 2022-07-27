/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:34:20 by hojinjang         #+#    #+#             */
/*   Updated: 2021/12/04 01:26:05 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_str;
	unsigned int	total_len;
	unsigned int	idx;

	if (!s1 || !s2)
		return (NULL);
	idx = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc(sizeof(char) * (total_len + 1));
	if (!(new_str))
		return (NULL);
	ft_memcpy(new_str, s1, ft_strlen(s1));
	ft_memcpy(new_str + ft_strlen(s1), s2, ft_strlen(s2));
	new_str[total_len] = '\0';
	return (new_str);
}
