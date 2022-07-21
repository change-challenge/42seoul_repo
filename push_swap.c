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

// int main(int argc, char **argv)
// {
//     char    **strs;
//     int     ac;

//     ac = parsing(&strs, argv + 1);
//     if (ac > 1)
//     {
//         if (!is_valid(strs, ac))
//         {
//             ft_putendl_fd("Error");
//             ft_free(strs);
//             exit(0);
//         }
//     }
// }
