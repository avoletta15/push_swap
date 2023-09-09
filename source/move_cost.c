#include "push_swap.h"

int	ft_movements_top(t_list *node, t_list **stack)
{
	t_list	**copy_stack;
	int		push_back;
	int		pull_front;

	pull_front = 0;
	push_back = 0;
	copy_stack = NULL;
	*copy_stack = *stack; 
	while (node != (*copy_stack))
	{
		(*copy_stack) = (*copy_stack)->next;
		push_back++;
	}
	while (node)
	{
		node = node->next;
		pull_front++;
	}
	if(push_back <= pull_front)
		return(push_back);
	else
		return(-(pull_front + 1));
}

int	finding_right_place(t_list *node,t_list **stack)
{
	t_list	**copy_stack;
	t_list 	*max;
	t_list 	*min;
	t_list 	*save;
	int		moves;	
	int		key;

	key = 0;
	copy_stack = stack;
	save = *copy_stack;
	while(copy_stack)
	{
		if(get_nbr((*copy_stack)) > get_nbr(node))
		{
			key += 1;
			max = *copy_stack;
			if(get_nbr(max) < get_nbr(save))
				save = max;
		}
		(*copy_stack) = (*copy_stack)->next;
	}
	if (key == 0)
	{
		*copy_stack = *stack;
		while (copy_stack)
		{
			if(get_nbr((*copy_stack)) < get_nbr(node))
			{
				key += 1;
				min = *copy_stack;
				if(get_nbr(min) > get_nbr(save))
					save = min;
			}
			(*copy_stack) = (*copy_stack)->next;
		}
	}
	moves = ft_movements_top(save, stack);
	return(moves);
}

t_list	*ft_find_cheapest(t_list **stack_a, t_list **stack_b, t_moves moves)
{
	t_list	**head;
	t_list	*cheapest;
	int		origin_moves;
	int		dest_moves;
	int		total_moves;
	int		total_moves_before;
	
	total_moves = 0;
	head = stack_a;
	cheapest = *head;
	while(head)
	{
		origin_moves = ft_movements_top(*head, stack_a);
		dest_moves = finding_right_place(*head, stack_b);
		if (origin_moves > 0 && dest_moves > 0)
		{
			if (origin_moves > dest_moves)
				total_moves = origin_moves;
			else
				total_moves = dest_moves;
		}
		else if (origin_moves < 0 && dest_moves < 0)
		{
			if (origin_moves < dest_moves)
				total_moves = origin_moves;
			else
				total_moves = dest_moves;
		}
		else
		{
			if (origin_moves < 0)
				origin_moves = -1 * (origin_moves);
			if (dest_moves < 0)
				dest_moves = -1 * (dest_moves);
			total_moves = origin_moves + dest_moves;
		}
		if(total_moves < total_moves_before)
		{
			cheapest = *head;
			moves.moves_a = origin_moves;
			moves.moves_b = dest_moves;
		}
		total_moves_before = total_moves;
		(*head) = (*head)->next;
	}
	return(cheapest);
}
