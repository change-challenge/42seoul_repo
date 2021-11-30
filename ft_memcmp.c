/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:22:33 by hchang            #+#    #+#             */
/*   Updated: 2021/11/30 15:31:50 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_1;
	const unsigned char	*s2_1;

	s1_1 = s1;
	s2_1 = s2;
	while (n--)
	{
		if (*s1_1 != *s2_1)
			return (*s1_1 - *s2_1);
		s1_1++;
		s2_1++;
	}
	return (0);
}
