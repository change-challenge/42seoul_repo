/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:22:20 by hchang            #+#    #+#             */
/*   Updated: 2021/11/29 18:29:56 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int					idx;
	unsigned char		*dst2;
	const unsigned char	*src2;

	idx = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	dst2 = dst;
	src2 = src;
	while (n)
	{
		dst2[idx] = src2[idx];
		n--;
		idx++;
	}
	return (dst2);
}

/*
int main()
{
	char src[] = "BlockDMask";
    char dest1[] = "1";
	char dest2[] = "1";
    char dest3[] = "abcdefghijklmnop";
	char dest4[] = "abcdefghijklmnop";
 
    // 메모리 복사1 : src 길이만큼만 복사
    memcpy(dest1, src, sizeof(char) * 10);
	ft_memcpy(dest2, src, sizeof(char) * 10);
 
    // 메모리 복사2 : src 길이 + 1 만큼 복사
    memcpy(dest3, src, sizeof(char) * 10 + 1);
 	ft_memcpy(dest4, src, sizeof(char) * 10 + 1);
    
	printf("dest1 : %s\n", dest1);
    printf("dest2 : %s\n", dest2);
	printf("dest3 : %s\n", dest3);
    printf("dest4 : %s\n", dest4);

}
*/