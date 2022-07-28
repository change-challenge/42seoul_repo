/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:30:54 by kyhan             #+#    #+#             */
/*   Updated: 2022/07/28 15:54:34 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *p, int c, size_t len)
{
	size_t	i;
	char	*arr;

	i = 0;
	arr = (char *)p;
	while (i < len)
	{
		arr[i] = (unsigned char)c;
		i++;
	}
	return ((void *)arr);
}
