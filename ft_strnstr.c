/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:22:54 by hchang            #+#    #+#             */
/*   Updated: 2021/11/30 20:27:31 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	char *result;

	if (needle == NULL)
		return (haystack);
	while (*haystack || len)
	{
		while (*haystack == *needle || *haystack || *needle)
		{
			
		}
		len--;
	}
}