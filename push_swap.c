#include "push_swap.h"

void ft_free(char **strs)
{
    int i;

    i = 0;
    while (strs[i])
        free (strs[i++]);
    free(strs);
}

int main(int argc, char **argv)
{
    char    **strs;
    int     ac;

    ac = parsing(&strs, argv + 1);
    if (ac > 1)
    {
        if (!is_valid(strs, ac))
        {
            ft_putendl_fd("Error");
            ft_free(strs);
            exit(0);
        }
    }
}