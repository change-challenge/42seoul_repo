/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:56:46 by hchang            #+#    #+#             */
/*   Updated: 2022/07/27 21:05:20 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_stack *stack_a)
{
	t_node	*node;

	node = pop_head(stack_a);
	if (node == 0)
		return ;
	push_tail(stack_a, node);
}

void	rb(t_stack *stack_b)
{
	t_node	*node;

	node = pop_head(stack_b);
	if (node == 0)
		return ;
	push_tail(stack_b, node);
}

void	rr(t_info info)
{
	ra(info.stack_a);
	rb(info.stack_b);
}
