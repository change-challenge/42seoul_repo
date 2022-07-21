#include "push_swap.h"

void	pa(t_info info)
{
	t_node	*node;

	node = pop_head(info.stack_b);
	if (node == 0)
		return ;
	push_head(info.stack_a, node);
	//ft_putendl_fd("pa", 1);
}

void	pb(t_info info)
{
	t_node	*node;

	node = pop_head(info.stack_a);
	if (node == 0)
		return ;
	push_head(info.stack_b, node);
	//ft_putendl_fd("pa", 1);
}

void	sa(t_stack *stack_a)
{
	int	tmp;

	if (stack_a->head == 0 || stack_a->head->next == 0)
		return ;
	tmp = stack_a->head->val;
	stack_a->head->val = stack_a->head->next->val;
	stack_a->head->next->val = tmp;
}

void	sb(t_stack *stack_b)
{
	int	tmp;

	if (stack_b->head == 0 || stack_b->head->next == 0)
		return ;
	tmp = stack_b->head->val;
	stack_b->head->val = stack_b->head->next->val;
	stack_b->head->next->val = tmp;
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

