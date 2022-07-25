#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*node;

	node = pop_head(stack_a);
	if (node == 0)
		return ;
	push_tail(stack_a, node);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack *stack_b)
{
	t_node	*node;

	node = pop_head(stack_b);
	if (node == 0)
		return ;
	push_tail(stack_b, node);
	ft_putendl_fd("rb", 1);
}

void	rr(t_info info)
{
	ra(info.stack_a);
	rb(info.stack_b);
	ft_putendl_fd("rr", 1);
}
