#include "checker.h"
#include "get_next_line/get_next_line.h"


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

void is_sorted_checker(t_stack *stack)
{
    t_node *curr;

	printf("====is_sorted_checker====\n");
    curr = stack->head;
    while (curr->next)
    {
        if (curr->val > curr->next->val)
        {
			ft_putendl_fd("KO", 1);
			return ;
		}
        curr = curr->next;
    }
    ft_putendl_fd("OK", 1);
}



int command_compare(char *line, t_info info)
{
	if (!ft_strncmp(line,"ra\n", 3))
		ra(info.stack_a);
	else if(!ft_strncmp(line,"rb\n", 3))
		rb(info.stack_b);
	else if(!ft_strncmp(line,"rr\n", 3))
		rr(info);
	else if(!ft_strncmp(line,"rra\n", 4))
		rra(info.stack_a);
	else if(!ft_strncmp(line,"rrb\n", 4))
		rrb(info.stack_b);
	else if(!ft_strncmp(line,"rrr\n", 4))
		rrr(info);
	else if(!ft_strncmp(line,"sa\n", 3))
		sa(info.stack_a);
	else if(!ft_strncmp(line,"sb\n", 3))
		sb(info.stack_b);
	else if(!ft_strncmp(line,"ss\n", 3))
		ss(info);
	else if(!ft_strncmp(line,"pa\n", 3))
		pa(info);
	else if(!ft_strncmp(line,"pb\n", 3))
		pb(info);
	else
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	return (1);
}


void	push_swap_read(int ac, int *arr, t_info info)
{
	char *line;
	t_node *curr;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
		{
			is_sorted_checker(info.stack_a);
			return ;
		}	
		int i = 0;
		command_compare(line, info);
		curr = info.stack_a->head;
		while (curr)
		{
			printf("%d 번째 : %d\n", i++, curr->idx);
			curr = curr->next;
		}
		free(line);
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
		push_swap_read(ac, arr, info);
		free(arr);
    }

    ft_free(strs);
}
