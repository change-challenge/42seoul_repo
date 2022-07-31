/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:57:53 by hchang            #+#    #+#             */
/*   Updated: 2022/07/31 13:18:13 by hchang           ###   ########.fr       */
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
	unsigned int	num;
	int				j;
	int				sign;
	int				*arr;

	arr = init_arr(strs, ac);
	while (strs[i])
	{
		num = 0;
		sign = 1;
		j = check_sign(strs[i], &sign);
		while (strs[i][j])
		{
			if (num > 214748364
				|| (num == 214748364 && (7 + (sign < 0)) < strs[i][j] - '0')
				|| !ft_isdigit(strs[i][j]))
				ft_error(strs);
			num = (num * 10) + (strs[i][j++] - '0');
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
