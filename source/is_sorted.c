#include "push_swap.h"

int	get_nbr(t_list *stack_a)
{
	return (*(int *)(stack_a->content));
}

int	ft_sorting_checker(t_list *stack_a)
{
	int	i;

	i = get_nbr(stack_a);
	while (stack_a)
	{
		if (i > get_nbr(stack_a))
			return (1);
		i = get_nbr(stack_a);
		stack_a = stack_a->next;
	}
	return (0);
}
