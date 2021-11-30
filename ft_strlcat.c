/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:22:42 by hchang            #+#    #+#             */
/*   Updated: 2021/11/30 17:59:11 by hchang           ###   ########.fr       */
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
	dst[dst_size + idx] = '\0';
	if (dst_size < dstsize)
		return (dst_size + src_size);
	return (dstsize + src_size);
}

// #include <stdio.h>
// int main()
// {
// 	char *dest = (char *)malloc(sizeof(*dest) * 15);
// 	memset(dest, 'r', 15);
// 	ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);
// 	printf("1. %s\n", dest);
// }