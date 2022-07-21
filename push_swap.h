/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankyuhong <hankyuhong@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 07:43:03 by sesim             #+#    #+#             */
/*   Updated: 2022/07/21 13:17:24 by hankyuhong       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				val;
	int				idx;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
}	t_stack;

typedef struct s_info
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_info;

t_node	*pop_head(t_stack *stack);
t_node	*pop_tail(t_stack *stack);
void	push_head(t_stack *stack, t_node *node);
void	push_tail(t_stack *stack, t_node *node);
void	pa(t_info info);
void	pb(t_info info);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_info info);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_info info);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_info info);
void    put_value(int *arr, t_stack *stack_a, int ac);
void    indexing(int *arr, t_stack *stack, int ac);
void    sort_3(t_stack *stack);
int is_sorted(t_stack *stack);


#endif
