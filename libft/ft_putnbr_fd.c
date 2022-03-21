/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:23:06 by hchang            #+#    #+#             */
/*   Updated: 2021/12/07 17:54:57 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;

	num = n;
	if (fd < 0)
		return ;
	if (num == -2147483648)
	{
		ft_putnbr_fd(num / 10, fd);
		write(fd, "8", 1);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (num >= 10)
			ft_putnbr_fd(num / 10, fd);
		num %= 10;
		num += '0';
		write(fd, &num, 1);
	}
}
