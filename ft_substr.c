/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:50:32 by hojinjang         #+#    #+#             */
/*   Updated: 2021/12/04 01:19:14 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	idx;

	idx = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	while (len)
	{
		new_str[idx] = s[start + idx];
		len--;
		idx++;
	}
	new_str[idx] = '\0';
	return (new_str);
}
