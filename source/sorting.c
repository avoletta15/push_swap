#include "push_swap.h"

void	ft_choosing_sort_method(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		ft_swap_out(stack_a, 'a');
	else if (ft_lstsize(*stack_a) == 3)
		ft_sorting_three(stack_a, 'a');
	else
		ft_sorting_larger_stack(stack_a, &stack_b);
	ft_lstclear(&stack_b, free_function);
}

void	ft_sorting_three(t_list **stack, char name_stack)
{
	if (get_nbr(*stack) > get_nbr((*stack)->next) \
		&& get_nbr(*stack) > get_nbr((*stack)->next->next))
	{
		if (get_nbr((*stack)->next) > get_nbr((*stack)->next->next))
		{
			ft_rotate_out(stack, name_stack);
			ft_swap_out(stack, name_stack);
		}
		else
			ft_rotate_out(stack, name_stack);
		return ;
	}
	else if ((get_nbr(*stack) > get_nbr((*stack)->next) && \
			get_nbr(*stack) < get_nbr((*stack)->next->next)) \
			|| (get_nbr(*stack) < get_nbr((*stack)->next) && \
			get_nbr(*stack) > get_nbr((*stack)->next->next)))
	{
		if (get_nbr(*stack) > get_nbr((*stack)->next))
			ft_swap_out(stack, name_stack);


		else if (get_nbr(*stack) < get_nbr((*stack)->next))
			ft_revrotate_out(stack, name_stack);
		return ;
	}
	else
	{
		ft_revrotate_out(stack, name_stack);
		ft_swap_out(stack, name_stack);
	}
}

void	ft_sorting_larger_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;
	t_moves	*moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	ft_push_out(stack_a, stack_b, 'b');
	ft_push_out(stack_a, stack_b, 'b');
	while(ft_lstsize(*stack_a) > 3)
	{
		cheapest = ft_find_cheapest(stack_a, stack_b, moves);
		printf("Cheapest: %d\n", get_nbr(cheapest));
		ft_from_origin_to_dest(stack_a, stack_b, moves, 'b');
	}
	if (ft_sorting_checker(*stack_a) == 1)
		ft_sorting_three(stack_a, 'a');
	while(ft_lstsize(*stack_b) > 0)
	{
		moves->moves_a = 0;
		moves->moves_b = 0;
		finding_right_place(*stack_b, stack_a);
		ft_from_origin_to_dest(stack_b, stack_a, moves, 'a');
	}
	free(moves);
}
