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
	ft_swap(stack_a);
}

void	sb(t_stack *stack_b)
{
	ft_swap(stack_b);
}

void	ss(t_info info)
{
	sa(info.stack_a);
	sb(info.stack_b);
}


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
	rra(info.stack_a);
	rrb(info.stack_b);
}

