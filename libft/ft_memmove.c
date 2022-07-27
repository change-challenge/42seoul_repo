/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:50:49 by hchang            #+#    #+#             */
/*   Updated: 2021/11/30 15:31:08 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst2;
	unsigned char		*src2;

	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		dst2 = (unsigned char *)dst;
		src2 = (unsigned char *)src;
		while (len--)
		{
			*dst2++ = *src2++;
		}
	}
	else
	{
		dst2 = (unsigned char *)dst + (len - 1);
		src2 = (unsigned char *)src + (len - 1);
		while (len--)
		{
			*dst2-- = *src2--;
		}
	}
	return (dst);
}
