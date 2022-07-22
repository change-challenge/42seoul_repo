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

int check_sign(char c, char next_c, int *sign)
{
    if (c == '+' && ft_isdigit(next_c))
        return (1);
    else if (c == '-' && ft_isdigit(next_c))
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
    ft_putendl_fd("Error", 2);
    exit (1);
}

int	is_dup(int *arr, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (arr[i] == arr[j])
		{
			free (arr);
			return (1);
		}
		j++;
	}
	return (0);
}

int	*ft_adtoi(char **strs, int ac)
{
    int         i;
    int         j;
    long long   num;
    int         sign;
	int			*arr;

	arr = ft_calloc(1, sizeof(int) * ac);
    sign = 1;
    i = 0;
    while(strs[i])
    {
		num = 0;
        j = 0;
        j += check_sign(strs[i][j], strs[i][j + 1], &sign);
        while (strs[i][j])
        {
            if (!(strs[i][j] >= '0' && strs[i][j] <= '9'))
                ft_error(strs);
            num += num * 10 + strs[i][j] - '0';
            j++;
        }
		if ((num > INT_MAX && sign == 1) || (num > INT_MAX + 1 && sign == -1))
        ft_error(strs);
		arr[i] = sign * num;
		if (is_dup(arr, i))
			ft_error(strs);
        i++;
    }
    return (arr);
}
