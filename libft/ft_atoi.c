/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:27:51 by minsuki2          #+#    #+#             */
/*   Updated: 2022/03/08 16:57:48 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static	int		plma_check(int c, int *sign);
static	int		ft_isspace(int c);
static	size_t	make_max(int sign);

int	ft_atoi(const char *str)
{
	int		sign;
	int		c;
	long	num;
	size_t	i;
	size_t	over_value;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	i += plma_check(str[i], &sign);
	over_value = make_max(sign);
	while (ft_isdigit(str[i]) && str[i])
	{
		c = str[i] - '0';
		if (num > (long)(over_value / 10) || (num == (long)(over_value / 10)
					&& c > (int)(over_value % 10)))
			return ((int)over_value);
		num = num * 10 + (long)c;
		i++;
	}
	return ((int)(sign * num));
}

static	size_t	make_max(int sign)
{
	if (sign == -1)
		return ((size_t)LONG_MIN);
	return ((size_t)LONG_MAX);
}

static	int	ft_isspace(int c)
{
	return ((c >= 0x09 && c <= 0x0d) || c == 0x20);
}

static	int	plma_check(int c, int *sign_ptr)
{
	size_t	n;

	n = 0;
	if (c == '+' || c == '-')
		if (n++ + 1 && c == '-')
			*sign_ptr *= -1;
	return (n);
}
