/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:38:42 by hchang            #+#    #+#             */
/*   Updated: 2021/12/03 17:16:05 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char	*ft_strrchr(const char *s, int c)
{
	int	idx;
	int	result_idx;
	int	s_len;
	int	flag;

	idx = 0;
	flag = 0;
	s_len = ft_strlen(s);
	if (c == '\0' || s == NULL)
		return ((char *)s + s_len);
	while (s[idx])
	{
		if (s[idx] == (unsigned char)c)
		{
			result_idx = idx;
			flag = 1;
		}	
		idx++;
	}
	if (flag)
		return ((char *)s + result_idx);
	return (0);
}
