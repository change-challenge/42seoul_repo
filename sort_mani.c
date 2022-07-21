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

void    b_to_a(t_info info)
{
    while (info.stack_b->size)
    {
        if (info.stack_b->head->idx > info.stack_b->tail->idx)
    }
    
}