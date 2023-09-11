#include "push_swap.h"

t_list	*new_node(char *av)
{
	int		*nbr;

	nbr = (int *)malloc(sizeof(int));
	if (!nbr)
		return (NULL);
	*nbr = ft_atoi(av);
	return (ft_lstnew(nbr));
}

int	main(int ac, char **av)
{
	int		j;
	t_list	*node;
	t_list	*stack_a;

	stack_a = NULL;
	j = 1;
	if (ac >= 3 && ft_arg_protection(av, ac) == 0)
	{
		while (j < ac)
		{
			node = new_node(av[j]);
			if (node)
			{
				ft_lstadd_back(&stack_a, node);
				j++;
			}
		}
	}
	else
		ft_error ();
	ft_printf("Stack_A Before:\n");
	display_nodes(stack_a);
	if (ft_sorting_checker(stack_a) == 1)
		ft_choosing_sort_method (&stack_a);
	ft_printf("Stack_A Before free:\n");
	display_nodes(stack_a);
	ft_lstclear(&stack_a, free_function);
	return (0);
}
