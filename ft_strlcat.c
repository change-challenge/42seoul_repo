/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:22:42 by hchang            #+#    #+#             */
/*   Updated: 2022/01/12 18:01:22 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	idx;

	idx = 0;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dstsize == 0)
		return (src_size);
	while ((dst_size + idx < dstsize - 1) && src[idx])
	{
		dst[dst_size + idx] = src[idx];
		idx++;
	}
	if (dst_size > dstsize)
		return (dstsize + src_size);
	dst[dst_size + idx] = '\0';
	return (dst_size + src_size);
}
