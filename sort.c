#include "push_swap.h"

static int min_num(t_stack *stack)
{
    t_node  *curr;
    int     tmp;

    curr = stack->head;
    tmp = curr->idx;
    while (curr->next)
    {
        if (tmp > curr->next->idx)
            tmp = curr->next->idx;
        curr = curr->next;
    }
    return (tmp);
}

static int max_num(t_stack *stack)
{
    t_node  *curr;
    int     tmp;

    curr = stack->head;
    tmp = curr->idx;
    while (curr->next)
    {
        if (tmp < curr->next->idx)
            tmp = curr->next->idx;
        curr = curr->next;
    }
    return (tmp);
}

int is_sorted(t_stack *stack)
{
    t_node *curr;

    curr = stack->head;
    while (curr->next)
    {
        if (curr->idx > curr->next->idx)
            return (0);
        curr = curr->next;
    }
    return (1);
}

void    sort_3(t_stack *stack)
{
    t_node *curr;
    int     top;
    int     mid;
    int     bottom;

    curr = stack->head;
    top = curr->idx;
    mid = curr->next->idx;
    bottom = curr->next->next->idx;
    if (mid == max_num(stack) && top == min_num(stack))
    {
        rra(stack);
        sa(stack);
    }
    else if (mid == min_num(stack) && bottom == max_num(stack))
        sa(stack);
    else if (mid == max_num(stack) && bottom == min_num(stack))
        rra(stack);
    else if (top == max_num(stack) && mid == min_num(stack))
        ra(stack);
    else if (top == max_num(stack) && bottom == min_num(stack))
    {
        ra(stack);
        sa(stack);
    }
}

int find_first(t_stack *stack, int flag)
{
    t_node *curr;
    int i;

    i = 1;
    curr = stack->head;
    while (curr)
    {
        if (curr->idx == flag)
            break ;
        curr = curr->next;
        i++;
    }
    return (i);
}

void    sort_5(t_stack *stack)
{
    t_node *curr;
    int     idx;
    
    curr = stack->head;
	idx = find_first(stack, 0);
	if (idx <= 3)
		while (--idx)
			ra(stack);
	else if (idx > 3)
		while (idx++ < 6)
			rra(stack);
}