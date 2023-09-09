#include "push_swap.h"

void	ft_choosing_sort_method(t_list **stack_a)
{
	/* t_list	*stack_b;

	stack_b = NULL; */
	if (ft_lstsize(*stack_a) == 2)
		ft_swap_out(stack_a, 'a');
	else if (ft_lstsize(*stack_a) == 3)
		ft_sorting_three(stack_a, 'a');
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
	t_moves	moves;

	ft_push_out(stack_a, stack_b, 'b');
	ft_push_out(stack_a, stack_b, 'b');
	while(ft_lstsize(*stack_a) > 3)
	{
		cheapest = ft_find_cheapest(stack_a, stack_b, moves);
		ft_making_movements(cheapest, stack_a, stack_b, moves);
		ft_push_out(stack_a, stack_b, 'b');
		(*stack_a) = (*stack_a)->next;
	}
}

void	ft_making_movements(t_list *cheapest, t_list **stack_a, t_list **stack_b, t_moves moves)
{
	while (stack_a || stack_b)
	{
		if (moves.moves_a > 0 && moves.moves_b > 0)
		{
			ft_revrotate_both(stack_a, stack_b);
			moves.moves_a--;
			moves.moves_b--;
		}
		else if (moves.moves_a < 0 && moves.moves_b < 0)
		{
			ft_revrotate_both(stack_a, stack_b);
			moves.moves_a++;
			moves.moves_b++;
		}
		else
		{
			if (moves.moves_a > 0)
				ft_rotate_out(stack_a, 'a');
			else if (moves.moves_a < 0)
				ft_rev_rotate_out(stack_a, 'a');
			if (moves.moves_b > 0)
				ft_rotate_out(stack_a, 'b');
			else if (moves.moves_b < 0)
				ft_rev_rotate_out(stack_a, 'b');	
		}
	}
}
