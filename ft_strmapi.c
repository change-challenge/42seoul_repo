/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:32:58 by hojinjang         #+#    #+#             */
/*   Updated: 2021/12/06 21:38:52 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			idx;
	char			*result;

	idx = 0;
	if (!s || !f)
		return (0);
	result = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (0);
	while (idx < ft_strlen(s))
	{
		result[idx] = f(idx, s[idx]);
		idx++;
	}
	result[idx] = '\0';
	return (result);
}
