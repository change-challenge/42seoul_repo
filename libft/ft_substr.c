/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:50:32 by hojinjang         #+#    #+#             */
/*   Updated: 2022/01/12 17:09:45 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	idx;

	idx = 0;
	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
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
