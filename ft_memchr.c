/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:22:13 by hchang            #+#    #+#             */
/*   Updated: 2021/11/29 21:33:23 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int idx;

	idx = 0;
	while (n)
	{
		if (((unsigned char *)s)[idx] == (unsigned char)c)
			return ((void *)s+idx);
		idx++;
		n--;
	}
	return (NULL);
}