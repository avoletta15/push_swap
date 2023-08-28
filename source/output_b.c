#include "push_swap.h"

void	ft_rb(t_list **stack)
{
	ft_rotate(stack);
	ft_putendl_fd("rb", 1);
}

void	ft_sb(t_list **stack)
{
	ft_swap(stack);
	ft_putendl_fd("sb", 1);
}

void	ft_rrb(t_list **stack)
{
	ft_rev_rotate(stack);
	ft_putendl_fd("rrb", 1);
}
