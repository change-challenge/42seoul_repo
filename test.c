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

//	bzero(&info, sizeof(t_info));	
	
	info.stack_a = calloc(1, sizeof(t_stack));
	info.stack_b = calloc(1, sizeof(t_stack));
	int i = 1;
	while(i <= 20)
	{
		node = calloc(1, sizeof(t_node));
		node->val = i;
		node->next = 0;
		//printf("node val : %d\n", node->val);
		push_head(info.stack_a, node);
//		printf("head val : %d\n", info.stack_a->head->val);
		i++;
	}
	ra(info.stack_a);
	ra(info.stack_a);
	rra(info.stack_a);
	rra(info.stack_a);
	pb(info);
	pb(info);
	pb(info);
	pb(info);
	pb(info);
	rb(info.stack_b);
	pa(info);
	rrr(info);
	t_node *curr;
	curr = info.stack_a->head;
	while(curr)
	{
		printf("val : %d\n", curr->val);
		curr = curr->next;
	}

	t_node *curr2;
	curr2 = info.stack_b->head;
		printf("----------------b--------\n");
	while(curr2)
	{
		printf("val : %d\n", curr2->val);
		curr2 = curr2->next;
	}
}
