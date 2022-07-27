/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:56:18 by hchang            #+#    #+#             */
/*   Updated: 2022/07/27 21:05:16 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_info info)
{
	t_node	*node;

	node = pop_head(info.stack_b);
	if (node == 0)
		return ;
	push_head(info.stack_a, node);
	info.stack_a->size++;
	info.stack_b->size--;
}

void	pb(t_info info)
{
	t_node	*node;

	node = pop_head(info.stack_a);
	if (node == 0)
		return ;
	push_head(info.stack_b, node);
	info.stack_a->size--;
	info.stack_b->size++;
}

void	sa(t_stack *stack_a)
{
	if (ft_swap(stack_a) == 0)
		return ;
}

void	sb(t_stack *stack_b)
{
	if (ft_swap(stack_b) == 0)
		return ;
}

void	ss(t_info info)
{
	if (ft_swap(info.stack_a) == 0)
		return ;
	if (ft_swap(info.stack_b) == 0)
		return ;
}
