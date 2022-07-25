#include "push_swap.h"

void	pa(t_info info)
{
	t_node	*node;

	node = pop_head(info.stack_b);
	if (node == 0)
		return ;
	push_head(info.stack_a, node);
	info.stack_a->size++;
	info.stack_b->size--;
	//ft_putendl_fd("pa", 1);
	printf("pa\n");
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
	printf("pb\n");
}

void	sa(t_stack *stack_a)
{
	ft_swap(stack_a);
	printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	ft_swap(stack_b);
	printf("sb\n");
}

void	ss(t_info info)
{
	sa(info.stack_a);
	sb(info.stack_b);
	printf("ss\n");
}


void	ra(t_stack *stack_a)
{
	t_node	*node;

	node = pop_head(stack_a);
	if (node == 0)
		return ;
	push_tail(stack_a, node);
	printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	t_node	*node;

	node = pop_head(stack_b);
	if (node == 0)
		return ;
	push_tail(stack_b, node);
	printf("rb\n");
}

void	rr(t_info info)
{
	ra(info.stack_a);
	rb(info.stack_b);
	printf("rr\n");
}

void	rra(t_stack *stack_a)
{
	t_node	*node;

	node = pop_tail(stack_a);
	if (node == 0)
		return ;
	push_head(stack_a, node);
	printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	t_node	*node;

	node = pop_tail(stack_b);
	if (node == 0)
		return ;
	push_head(stack_b, node);
	printf("rrb\n");
}

void	rrr(t_info info)
{
	rra(info.stack_a);
	rrb(info.stack_b);
}

