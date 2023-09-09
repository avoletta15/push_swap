#include "push_swap.h"

void	ft_swap_out(t_list **stack, char name_stack)
{
	ft_swap(stack);
	if (name_stack == 'a')
		ft_putendl_fd("sa", 1);
	else if (name_stack == 'b')
		ft_putendl_fd("sb", 1);
}

void	ft_rotate_out(t_list **stack, char name_stack)
{
	ft_rotate(stack);
	if (name_stack == 'a')
		ft_putendl_fd("ra", 1);
	else if (name_stack == 'b')
		ft_putendl_fd("rb", 1);
}

void	ft_rotate_both(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}


void	ft_revrotate_out(t_list **stack, char name_stack)
{
	ft_rev_rotate(stack);
	if (name_stack == 'a')
		ft_putendl_fd("rra", 1);
	else if (name_stack == 'b')
		ft_putendl_fd("rrb", 1);
}

void	ft_revrotate_both(t_list **stack_a, t_list **stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	ft_putendl_fd("rrv", 1);
}

void	ft_push_out(t_list **origin, t_list **dest, char name_stack)
{
	ft_push(origin, dest);
	if (name_stack == 'a')
		ft_putendl_fd("pa", 1);
	else if (name_stack == 'b')
		ft_putendl_fd("pb", 1);
}