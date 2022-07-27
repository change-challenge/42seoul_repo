/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:21:53 by hojinjang         #+#    #+#             */
/*   Updated: 2021/12/06 20:49:01 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(long long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			minus;
	char		*result;
	long long	int_len;
	long long	num;

	minus = 1;
	num = (long long) n;
	int_len = ft_intlen(num);
	if (n < 0)
	{
		minus *= -1;
		num = - (long long) n;
	}
	result = malloc(sizeof(char) * int_len + 1);
	if (!(result))
		return (NULL);
	result[int_len] = 0;
	while (int_len-- > 0)
	{
		result[int_len] = (num % 10) + '0';
		num /= 10;
	}
	if (minus == -1)
		result[0] = '-';
	return (result);
}
