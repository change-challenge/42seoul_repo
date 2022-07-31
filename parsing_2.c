/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:57:53 by hchang            #+#    #+#             */
/*   Updated: 2022/07/31 12:17:41 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*init_arr(char **strs, int ac)
{
	int	*arr;

	arr = ft_calloc(1, sizeof(int) * ac);
	if (arr == 0)
		ft_error(strs);
	return (arr);
}

int	*ft_adtoi(int i, char **strs, int ac)
{
	int	num;
	int	j;
	int	sign;
	int	*arr;

	arr = init_arr(strs, ac);
	while (strs[i])
	{
		num = 0;
		sign = 1;
		j = check_sign(strs[i][0], strs[i][1], &sign);
		while (strs[i][j])
		{
			num *= 10;
			num += (strs[i][j] - '0');
			if (!ft_isdigit(strs[i][j++]))
				ft_error(strs);
		}
		arr[i] = sign * num;
		if ((sign == 1 && arr[i] < 0) || (sign == -1 && arr[i] > 0)
			|| (is_dup(arr, i++)))
			ft_error(strs);
	}
	return (arr);
}

void	ft_error_null(char *line)
{
	free(line);
	ft_putendl_fd("Error", 2);
	exit(1);
}
