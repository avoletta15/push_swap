#include "push_swap.h"

int	get_nbr(t_list *stack)
{
	return (*(int *)(stack->content));
}

int	ft_sorting_checker(t_list *stack)
{
	int	i;

	i = get_nbr(stack);
	while (stack)
	{
		if (i > get_nbr(stack))
			return (1);
		i = get_nbr(stack);
		stack = stack->next;
	}
	return (0);
}

int	ft_sorting_checker_two(t_list *stack)
{
	int	i;

	i = get_nbr(stack);
	while (stack)
	{
		if (i < get_nbr(stack))
			return (1);
		i = get_nbr(stack);
		stack = stack->next;
	}
	return (0);
}
