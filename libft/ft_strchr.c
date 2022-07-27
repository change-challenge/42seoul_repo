/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:42:04 by hchang            #+#    #+#             */
/*   Updated: 2021/11/30 19:15:06 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	idx;
	int	s_len;

	idx = 0;
	s_len = ft_strlen(s);
	if (c == '\0' || s == NULL)
		return ((char *)s + s_len);
	while (s[idx])
	{
		if (s[idx] == (unsigned char)c)
			return ((char *)s + idx);
		idx++;
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
// 	char str2[] = "bonjour";
// 	char str3[] = "";
// 	char str4[] = "bonjour";
// 	printf("1. %s\n", ft_strchr(str2, '\0'));
// 	printf("2. %s\n", ft_strchr(str3, '\0'));
// 	printf("3. %s\n", ft_strchr(str4, 'j'));
// }