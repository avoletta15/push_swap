#include "push_swap.h"

t_list	*new_node(char *av)
{
	int		*nbr;

	nbr = (int *)malloc(sizeof(int));
	if (!nbr)
		return(NULL);
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
	if(ac >= 3 && ft_arg_protection(av, ac) == 0) /* minimun 2 numbers to sort & protections */
	{
		while(j < ac)
		{	
			
			node = new_node(av[j]);
			if(node) /* creation of a linked list by adding nodes at the end of it */
			{
				ft_lstadd_back(&stack_a, node);
				j++;
			}
		}
	}
	else
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	if(ft_is_sorted(stack_a) == 1)
	{
		ft_organizing_sort_type(&stack_a);
	}
	return(0);
}