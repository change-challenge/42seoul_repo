/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:45:55 by kyhan             #+#    #+#             */
/*   Updated: 2022/07/28 15:54:46 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strnstr(const char *hay, const char *nid, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*nid == '\0')
	{
		return ((char *)hay);
	}
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (hay[i + j] == nid[j] && (i + j) < len)
		{
			j++;
			if (nid[j] == '\0')
			{
				return ((char *)(&hay[i]));
			}
		}
		i++;
	}
	return (0);
}
