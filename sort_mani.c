#include "push_swap.h"

void    a_to_b(t_info info, int chunk)
{
    t_node *curr;

    curr = info.stack_a->head;
    while (info.stack_a->size)
    {
        if (curr->idx <= info.stack_b->size)
            pb(info);
        else if (curr->idx > info.stack_b->size && curr->idx < info.stack_b->size + chunk)
        {
            pb(info);
            rb(info.stack_b);
        }
        else if (curr->idx >= info.stack_b->size + chunk)
            ra(info.stack_a);
    }
}

void    sort_b(t_stack *stack)
{
    t_node  *curr;
    int i;

    i = 0;
    curr = stack->head;
    while ((stack->size - 1) != curr->idx)
    {
        i++;
		curr = curr->next;
    }
	while (i <= stack->size / 2 && i--)
		rb(stack);
	while (i > stack->size / 2 && i < stack->size && i++)
		rrb(stack);
}

void    b_to_a(t_info info)
{
    while (info.stack_b->size)
    {
        sort_b(info.stack_b);
		pa(info);
    }
}