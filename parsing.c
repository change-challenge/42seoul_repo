#include "push_swap.h"

int parsing(char ***strs, char **argv)
{
    char    *line;
    char    *tmp;
    int     ret;

    ret = 0;
    line = 0;
    while (*argv)
    {
        if (!line)
            line = ft_strdup(*argv++);
        else
        {
            tmp = line;
            line = ft_strjoin(line, " "); //gnl join으로 free
            free(tmp);
            tmp = line;
            line = ft_strjoin(line, *argv++);
            free(tmp);
        }
    }
    *strs = ft_split(line, " ");
    free(line);
    while (**strs)
        *strs[ret++];
    return (ret);
}

int check_sign(char c, int *sign)
{
    if (c == '+')
        return (1);
    else if (c == '-')
    {
        *sign = -1;
        return (1);
    }
    else
        return (0);
}

void    ft_error(char **strs)
{
    ft_free(strs);
    ft_putendl_fd("Error");
    exit (0);
}

void    is_int(char **strs)
{
    int         i;
    int         j;
    long long   num;
    int         sign;

    sign = 1;
    i = 0;
    while(strs[i])
    {
        j = 0;
        j += check_sign(strs[i][j], &sign);
        while (strs[i][j])
        {
            if (!(strs[i][j] >= '0' && strs <= '9'))
                ft_error(strs);
            num += num * 10 + strs[i][j] - '0';
            j++;
        }
        i++;
    }
    if (num > INT_MAX || num < INT_MIN)
        ft_error(strs);
    return (sign * num);
}

int is_valid(char **strs, int ac)
{
    int *arr;

    arr = malloc(sizeof(int) * ac);
    if (!arr)
        return (0);
    is_int(**strs)
    is_dup()
}