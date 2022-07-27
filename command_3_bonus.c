/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_3_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:56:58 by hchang            #+#    #+#             */
/*   Updated: 2022/07/27 21:05:25 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_stack *stack_a)
{
	t_node	*node;

	node = pop_tail(stack_a);
	if (node == 0)
		return ;
	push_head(stack_a, node);
}

void	rrb(t_stack *stack_b)
{
	t_node	*node;

	node = pop_tail(stack_b);
	if (node == 0)
		return ;
	push_head(stack_b, node);
}

void	rrr(t_info info)
{
	t_node	*node;

	node = pop_tail(info.stack_a);
	if (node == 0)
		return ;
	push_head(info.stack_a, node);
	node = pop_tail(info.stack_b);
	if (node == 0)
		return ;
	push_head(info.stack_b, node);
}
