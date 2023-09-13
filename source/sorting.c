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
	t_moves	*moves;
	t_list	*copy;

	moves = (t_moves *)malloc(sizeof(t_moves));
	ft_push_out(stack_a, stack_b, 'b');
	ft_push_out(stack_a, stack_b, 'b');
	moves->origin_char = 'a';
	moves->dest_char = 'b';
	while(ft_lstsize(*stack_a) > 3)
	{
		ft_find_cheapest(stack_a, stack_b, moves);
		ft_from_origin_to_dest(stack_a, stack_b, moves, 'b');
	}
	if (ft_sorting_checker(*stack_a) == 1)
	{
		if (ft_lstsize(*stack_a) == 2)
			ft_swap_out(stack_a, 'a');
		else if (ft_lstsize(*stack_a) == 3)
			ft_sorting_three(stack_a, 'a');
	}
	moves->origin_char = 'b';
	moves->dest_char = 'a';
	while(ft_lstsize(*stack_b) > 0)
	{
		moves->origin = 0;
		moves->dest = back_to_a(*stack_b, stack_a);
		ft_from_origin_to_dest(stack_b, stack_a, moves, 'a');
	}
	copy = *stack_a;
	while(min_in_the_stack(*stack_a) != get_nbr(copy))
		copy = copy->next;
	moves->origin = ft_movements_top(copy, stack_a);
	moves->dest = 0;
	moves->origin_char = 'a';
	ft_organizing_stack(stack_a, stack_b, moves);
	free(moves);
}
