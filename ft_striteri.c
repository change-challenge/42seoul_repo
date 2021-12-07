/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:27:14 by hojinjang         #+#    #+#             */
/*   Updated: 2021/12/06 21:45:36 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = ft_strlen(s);
	if (!s && !f)
		return ;
	while (sidx < len)
	{
		(*f)(idx, s);
		s++;
		idx++;
	}
}
