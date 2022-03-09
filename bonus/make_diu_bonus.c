/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_diu_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:54:38 by minsuki2          #+#    #+#             */
/*   Updated: 2022/03/09 14:22:07 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	input_dec_base(char *dst, unsigned int nbr, int len)
{
	if (len)
	{
		input_dec_base(dst, nbr / DEC, len - 1);
		if (!nbr)
			dst[len - 1] = '0';
		else
			dst[len - 1] = DEC_BASE[nbr % DEC];
	}
}

static void	ft_inputnbr(char *str, int bits, int n, int len)
{
	if ((bits & CV_U) || n >= 0)
		input_dec_base(str, n, len);
	else
		input_dec_base(str, -n, len);
}

static void	ft_handle_sign(int arg, int bits, char *dst)
{
	int		idx;
	char	sign;

	if (arg < 0)
		sign = '-';
	else
	{
		sign = ' ';
		if (bits & FG_PLUS)
			sign = '+';
	}
	idx = 1;
	if (bits & FG_MINUS)
		dst[0] = sign;
	else
	{
		while (dst[idx] && !ft_strchr(DEC_BASE, dst[idx]))
			idx++;
		dst[idx - 1] = sign;
	}
}

static char	*make_str(int arg, t_gather *fwp, int len, int full_len)
{
	char	*dst;

	if ((fwp->bits & FG_ZERO) && (salloc_int(&dst, full_len, '0') == ERROR))
		return (NULL);
	else if (!(fwp->bits & FG_ZERO)
		&& (salloc_int(&dst, full_len, ' ') == ERROR))
		return (NULL);
	if (fwp->bits & FG_MINUS)
		ft_inputnbr(dst + isfg_inc(fwp), fwp->bits, arg, len);
	else
		ft_inputnbr(dst + full_len - len, fwp->bits, arg, len);
	if (fwp->bits & CV_D && (arg < 0 || fwp->bits & (FG_PLUS | FG_SPACE)))
		ft_handle_sign(arg, fwp->bits, dst);
	return (dst);
}

char	*make_diu(t_gather *fwp, int arg, int *cnt, int len)
{
	int		full_len;

	if (!(fwp->bits & CV_U) && arg < 0)
		fwp->bits |= FG_PLUS;
	full_len = measure_len_diuxp(fwp, &len);
	if (full_len == ERROR)
		return (NULL);
	if (check_max(cnt, full_len) == ERROR)
		return (NULL);
	return (make_str(arg, fwp, len, full_len));
}
