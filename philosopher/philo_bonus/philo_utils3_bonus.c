/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:09:04 by hchang            #+#    #+#             */
/*   Updated: 2022/09/14 01:32:59 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		idx;
	long	minus;
	long	result;

	idx = 0;
	result = 0;
	minus = 1;
	while (ft_isspace(str[idx]))
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			minus *= -1;
		idx++;
	}
	while (str[idx])
	{
		result = (result * 10) + (str[idx] - '0');
		if ((result > 2147483647 && minus == 1) || !ft_isdigit(str[idx])
			|| (result > 2147483648 && minus == -1))
			return (0);
		idx++;
	}
	return (minus * result);
}
