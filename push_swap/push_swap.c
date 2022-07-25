#include "push_swap.h"
#include <stdlib.h>

void    put_value(int *arr, t_stack *stack_a, int ac)
{
    int i;
    t_node  *node;

    i = 0;
    stack_a->size = ac;
    while(i < ac)
    {
        node = calloc(1, sizeof(t_node)); //libft 사용해야함.
        node->val = arr[i];
        push_tail(stack_a, node);
        ++i;
    }
}

void ft_free(char **strs)
{
    int i;

    i = 0;
    while (strs[i])
        free (strs[i++]);
    free(strs);
}

void    struct_free(t_info info)
{
    t_node  *curr;
    t_node  *tmp;

    curr = info.stack_a->head;
    while (curr)
    {
        tmp = curr;
        curr = curr->next;
        tmp->val = 0;
        tmp->idx = 0;
        free(tmp);
    }
}

int main(int argc, char **argv)
{
    char    **strs;
    int     ac;
    int     *arr;
    t_info  info;
    
    if (argc < 2)
        return (0);
    ac = parsing(&strs, argv + 1);
    if (ac > 1)
    {
		info.stack_a = calloc(1, sizeof(t_stack));
		info.stack_b = calloc(1, sizeof(t_stack));
        arr = ft_adtoi(strs, ac);
        put_value(arr, info.stack_a, ac);
		indexing(arr, info.stack_a, ac);
        free(arr);
		if (is_sorted(info.stack_a) == 1)
            return (0);
        sort(info);
    }
    ft_free(strs);
}
