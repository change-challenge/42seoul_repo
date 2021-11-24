/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:50:49 by hchang            #+#    #+#             */
/*   Updated: 2021/11/24 20:39:27 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char 		*dst2;
	const unsigned char *src2;
	
	dst2 = dst;
	src2 = src;


	


}

#include <stdio.h>

int main()
{
	char src[] = "hojin";
    char dest1[] = "123\0";
	char dest2[] = "456";
    char dest3[] = "51123123";
	char dest4[] = "4123123";
 
    
    printf("1. %s\n", memmove(dest1, src, 4));
	printf("2. %s\n", memmove(dest2, src, 4));
    printf("3. %s\n", memmove(dest3, src, 3));
 	printf("4. %s\n", memmove(dest4, src, 4));


}