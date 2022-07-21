#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int ac, char **av)
{
	if (ac == 2)
		printf("av : %s\n", av[1]);
	t_info info;
	t_node *node;
	int arr[4] = {1,9,0,6};
//	bzero(&info, sizeof(t_info));

	info.stack_a = calloc(1, sizeof(t_stack));
	info.stack_b = calloc(1, sizeof(t_stack));
	int i = 1;
// 	while(i <= 20)
// 	{
// 		node = calloc(1, sizeof(t_node));
// 		node->val = i;
// 		node->next = 0;
// 		//printf("node val : %d\n", node->val);
// 		push_head(info.stack_a, node);
// //		printf("head val : %d\n", info.stack_a->head->val);
// 		i++;
// 	}

	put_value(arr, info.stack_a, 4);

	t_node *curr;
	curr = info.stack_a->head;
	indexing(arr, info.stack_a, 4);

	if (is_sorted(info.stack_a))
		return (0);
	sort_4(info);
	curr = info.stack_a->head;
	// while(curr)
	// {
	// 	printf("value : %d\n", curr->val);
	// 	printf("idx : %d\n", curr->idx);
	// 	curr = curr->next;
	// }

	// t_node *curr2;
	// curr2 = info.stack_b->head;
	// 	printf("----------------b--------\n");
	// while(curr2)
	// {
	// 	printf("val : %d\n", curr2->val);
	// 	curr2 = curr2->next;
	// }
}
