/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:00:48 by sesim             #+#    #+#             */
/*   Updated: 2022/07/19 09:04:53 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft_src/libft.h"

void	ft_error(char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
	exit (1);
}

int	arg_check(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 2)
		return (0);
	while (av[i])
	{
		if (av[i][0] != '0' && ft_adtoi(av[i]) == 0)
			ft_error("Invalid argument");
	}
}
