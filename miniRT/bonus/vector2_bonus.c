/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:41:39 by jinypark          #+#    #+#             */
/*   Updated: 2022/10/18 16:36:06 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_vec	vec_div_double(t_vec u, double n)
{
	return (vec_multi_double(u, (1 / n)));
}

t_vec	vec_min(t_vec vec1, t_vec vec2)
{
	if (vec1.x > vec2.x)
		vec1.x = vec2.x;
	if (vec1.y > vec2.y)
		vec1.y = vec2.y;
	if (vec1.z > vec2.z)
		vec1.z = vec2.z;
	return (vec1);
}

double	vec_dot(t_vec u, t_vec v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vec	vec_cross(t_vec u, t_vec v)
{
	t_vec	init;

	init.x = u.y * v.z - u.z * v.y;
	init.y = u.z * v.x - u.x * v.z;
	init.z = u.x * v.y - u.y * v.x;
	return (init);
}

double	vec_len(t_vec u)
{
	return (sqrt(u.x * u.x + u.y * u.y + u.z * u.z));
}
