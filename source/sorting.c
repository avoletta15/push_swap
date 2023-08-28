#include "push_swap.h"

void	ft_organizing_sort_type(t_list **stack_a)
{
	// t_list	*stack_b;

	// stack_b = NULL;
	if(ft_lstsize(*stack_a) == 2)
		ft_swap(stack_a);
	if(ft_lstsize(*stack_a) == 3)
		ft_sorting_three(stack_a);

}

void	ft_sorting_three(t_list **stack)
{
	if(get_nbr(*stack) > get_nbr((*stack)->next) && get_nbr(*stack) > get_nbr((*stack)->next->next))
	{
		if(get_nbr((*stack)->next) > get_nbr((*stack)->next->next))
		{
			ft_ra(stack);
			ft_sa(stack);
		}
		else
			ft_ra(stack);
		return ;
	}
	else if((get_nbr(*stack) > get_nbr((*stack)->next) && get_nbr(*stack) < get_nbr((*stack)->next->next)) \
			|| (get_nbr(*stack) < get_nbr((*stack)->next) && get_nbr(*stack) > get_nbr((*stack)->next->next)))
	{
		if(get_nbr(*stack) > get_nbr((*stack)->next))
			ft_sa(stack);
		else if(get_nbr(*stack) < get_nbr((*stack)->next))
			ft_rra(stack);
		return ;
	}
	else
	{
		ft_rra(stack);
		ft_sa(stack);
	}
}

