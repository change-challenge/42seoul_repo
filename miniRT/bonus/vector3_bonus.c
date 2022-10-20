/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:41:36 by jinypark          #+#    #+#             */
/*   Updated: 2022/10/18 16:36:06 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

double	vec_len_sqr(t_vec u)
{
	return (u.x * u.x + u.y * u.y + u.z * u.z);
}

t_vec	vec_unit(t_vec u)
{
	return (vec_div_double(u, vec_len(u)));
}
