#include "push_swap.h"

void	ft_organizing_sort_type(t_list **stack_a)
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
