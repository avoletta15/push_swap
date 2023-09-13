#include "push_swap.h"

int	ft_movements_top(t_list *node, t_list **stack)
{
	t_list	*copy_stack;
	int		push_back;
	int		pull_front;

	copy_stack = *stack;
	pull_front = 0;
	push_back = 0;
	// ft_printf("\n\nComming node: %i\n\n", get_nbr(node));
	while (node != (copy_stack))
	{
		(copy_stack) = (copy_stack)->next;
		push_back++;
	}
	while (node)
	{
		node = node->next;
		pull_front++;
	}
	if(get_nbr(copy_stack) == 81)
	{
		ft_printf("\n===================\n");
		ft_printf("For number %i pb: %i\n", get_nbr(copy_stack), push_back);
		ft_printf("For number %i pf: %i\n", get_nbr(copy_stack), pull_front);
		ft_printf("===================\n\n");
	}
	if(push_back < pull_front)
		return(push_back);
	else
		return(-(pull_front));
}

int	max_in_the_stack(t_list *stack)
{
	int	nbr;

	nbr = get_nbr(stack);
	while(stack)
	{
		if(get_nbr(stack) > nbr)
			nbr = get_nbr(stack);
		stack = stack->next;
	}
	return(nbr);
}

int	min_in_the_stack(t_list *stack)
{
	int	nbr;

	nbr = get_nbr(stack);
	while(stack)
	{
		if(get_nbr(stack) < nbr)
			nbr = get_nbr(stack);
		stack = stack->next;
	}
	return(nbr);
}

int	ft_head_or_tail(t_list *stack, t_list *node)
{
	if ((get_nbr(node) > max_in_the_stack(stack)) 
		|| get_nbr(node) < min_in_the_stack(stack))
		return(0);
	return(1);
}

int	finding_right_place(t_list *node,t_list **stack)
{
	t_list	*copy_stack;
	t_list 	*position;
	int		moves;	
	int		key;


	key = 0;
	copy_stack = *stack;
	moves = 0;
	position = copy_stack;
	// printf("Inicio da Stack_B: %d\n", get_nbr(copy_stack));
	if (ft_head_or_tail(copy_stack, node) == 0)
	{
		// ft_printf("=======================\n");
		// ft_printf("Edges: %i\n", get_nbr(node));
		key = max_in_the_stack(copy_stack);
		// ft_printf("Max in Stack_b: %i\n", key);
		while (key != get_nbr(copy_stack))
			copy_stack = copy_stack->next;
		// ft_printf("Max in Moves to TOP: %i\n", get_nbr(copy_stack));
		moves = ft_movements_top(copy_stack, stack);
		// ft_printf("Moves: %d node: %d\n", moves, get_nbr(node));
		return(moves);
	}
	else
	{	
		while(copy_stack)
		{
			if(get_nbr((copy_stack)) > get_nbr(node))
			{
				if(copy_stack->next && get_nbr(copy_stack->next) < get_nbr(node))
				{
					position = copy_stack->next;
					break ;
				}
				else if ((copy_stack->next == NULL) && get_nbr(*stack) < get_nbr(node))
				{
					position = *stack;
					break ;
				}
			}
			(copy_stack) = (copy_stack)->next;
		}
	}
	// ft_printf("Position: %d nbr: %d\n", get_nbr(position), get_nbr(node));
	moves = ft_movements_top(position, stack);
	return(moves);
}

t_list	*ft_find_cheapest(t_list **stack_a, t_list **stack_b, t_moves *moves)
{
	t_list	*copy_stack;
	t_list	*cheapest;
	int		origin_moves;
	int		dest_moves;
	int		total_moves;
	int		total_moves_before;
	// static int		number_calls;
	
	total_moves = 0;
	copy_stack = *stack_a;
	cheapest = copy_stack;
	total_moves_before = INT_MAX;
	// ft_printf("number of calls: %i\n", ++number_calls);
	while(copy_stack)
	{
		origin_moves = ft_movements_top(copy_stack, stack_a);
		dest_moves = finding_right_place(copy_stack, stack_b);
		// ft_printf("Analized number: %i\n", get_nbr(copy_stack));
		// ft_printf("moves_a of %i: %i\n", get_nbr(copy_stack), origin_moves);
		// ft_printf("moves_b of %i: %i\n", get_nbr(copy_stack), dest_moves);
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
				total_moves = -1 * (origin_moves);
			else
				total_moves = -1 * (dest_moves);
		}
		else
		{
			if (origin_moves <= 0)
				total_moves = (-1 * origin_moves) + dest_moves;
			else 
				total_moves = origin_moves + (-1 * dest_moves);
		}
		if(total_moves < total_moves_before)
		{
			cheapest = copy_stack;
			moves->origin = origin_moves;
			moves->dest = dest_moves;
			total_moves_before = total_moves;
		}
		// ft_printf("total moves for %i: %i \n", get_nbr(copy_stack), total_moves);
		// ft_printf("=======================\n");
		(copy_stack) = (copy_stack)->next;
	}
	// ft_printf("cheapest: %i\n", get_nbr(cheapest));
	return(cheapest);
}
