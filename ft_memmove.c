/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:50:49 by hchang            #+#    #+#             */
/*   Updated: 2021/11/29 19:05:29 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int					idx;
	unsigned char		*dst2;
	const unsigned char	*src2;

	dst2 = dst;
	src2 = src;
	idx = 0;
	while (len)
	{
		*dst2 = src2[idx];
		len--;
		idx++;
		dst2++;
	}
	return (dst);
}
