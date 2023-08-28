#include "push_swap.h"

void	ft_sa(t_list **stack)
{
	ft_swap(stack);
	ft_putendl_fd("sa", 1);
}

void	ft_ra(t_list **stack)
{
	ft_rotate(stack);
	ft_putendl_fd("ra", 1);
}

void	ft_rra(t_list **stack)
{
	ft_rev_rotate(stack);
	ft_putendl_fd("rra", 1);
}
