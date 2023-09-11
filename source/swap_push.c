#include "push_swap.h"

void	ft_swap_out(t_list **stack, char name_stack)
{
	ft_swap(stack);
	if (name_stack == 'a')
		ft_putendl_fd("sa", 1);
	else if (name_stack == 'b')
		ft_putendl_fd("sb", 1);
}

void	ft_push_out(t_list **origin, t_list **dest, char name_stack)
{
	ft_push(origin, dest);
	if (name_stack == 'a')
		ft_putendl_fd("pa", 1);
	else if (name_stack == 'b')
		ft_putendl_fd("pb", 1);
}