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
	ft_putendl_fd("pa", 1);
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
	ft_putendl_fd("pb", 1);
}

void	sa(t_stack *stack_a)
{
	if (ft_swap(stack_a) == 1)
		return ;
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack *stack_b)
{
	if (ft_swap(stack_b) == 1)
		return ;
	ft_putendl_fd("sb", 1);
}

void	ss(t_info info)
{
	if (ft_swap(info.stack_a) == 0)
		return ;
	if (ft_swap(info.stack_b) == 0)
		return ;
	ft_putendl_fd("ss", 1);
}
