/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:00:11 by sesim             #+#    #+#             */
/*   Updated: 2022/07/20 18:30:12 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	push_tail(t_stack stack_a, int num)
{
	t_node	*node;
	t_node	*elem;

	elem = ft_calloc(1, sizeof(t_node));
	elem->val = num;
	node = stack_a.top;
	while (node != 0)
		node = node->next;
	node = elem;
}
*/

void	push_head(t_stack *stack, t_node *node)
{
	
	node->next = stack->head;
	stack->head = node;
}

t_node	*pop_head(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	if (node == 0)
		return (0);
	stack->head = node->next;
	node->next = 0;
	return (node);
}

void	push_tail(t_stack *stack, t_node *node)
{
	t_node	*curr;

	curr = stack->head;
	if (curr == 0)
		stack->head = node;
	while (curr->next != 0)
		curr = curr->next;
	curr->next = node;
	stack->tail = node;
}

t_node	*pop_tail(t_stack *stack)
{
	t_node	*curr;
	t_node	*res;

	curr = stack->head;
	if (curr == 0)
		return (0);
	while (curr->next != stack->tail)
		curr = curr->next;
	stack->tail = curr;
	res = curr->next;
	curr->next = 0;
	return (res);
}

void	ft_swap(t_stack stack)
{
	int	tmp;

	if (stack.head == 0 || stack.head->next == 0)
		return ;
	tmp = stack.head->val;
	stack.head->val = stack.head->next->val;
	stack.head->next->val = tmp;
}


