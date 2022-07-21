#include "push_swap.h"
#include <stdio.h>

static void ft_swap(int *a, int *b)
{
	int tmp_a;

	tmp_a = *a;
	*a = *b;
	*b = tmp_a;
}

void q_sort(int *data, int l, int r)
{
	int	left;
	int	right;
	int pivot;

	pivot = data[(l + r) / 2];
	left = l;
	right = r;
	while(left <= right)
	{
		while(data[left] < pivot)
			left++;
		while(data[right] > pivot)
			right--;

		if (left <= right)
			ft_swap(&data[left++], &data[right--]);
	}
	if (l < right)
		q_sort(data, l, right);
	if (r > left)
		q_sort(data, left, r);
}

void    indexing(int *arr, t_stack *stack, int ac)
{
    int i;
    t_node *curr;

    curr = stack->head;
    q_sort(arr, 0, ac - 1);
    while (curr)
    {
        i = 0;
        while (i < ac)
        {
            if (arr[i] == curr->val)
            {
                curr->idx = i;
                break ;
            }
            i++;
        }
        curr = curr->next;
    }
}