/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:27:14 by hojinjang         #+#    #+#             */
/*   Updated: 2022/01/12 20:20:13 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	idx;
	size_t	len;

	idx = 0;
	if (!s || !f)
		return ;
	len = ft_strlen(s);
	while (idx < len)
	{
		(*f)(idx, s);
		s++;
		idx++;
	}
}
