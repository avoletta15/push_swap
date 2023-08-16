#include "push_swap.h"

int	main(int ac, char **av)
{
	int		j;
	t_list	*node;
	t_list	*save;
	t_list	**head_a;
	int		*nbr;

	j = 1;
	if(ac >= 3 && ft_arg_protection(av, ac) == 0) /* minimun 2 numbers to sort & protections */
	{
		nbr = (int *)malloc(sizeof(int));
		if (!nbr)
			return (0);
		*nbr = ft_atoi(av[j]);
		node = ft_lstnew(nbr);
		head_a = &node;
		if(node) /* creation of a linked list by adding nodes at the end of it */
		{
			j++;
			while(j < ac)
			{
				nbr = (int *)malloc(sizeof(int));
				if (!nbr)
					return (0);
				*nbr = ft_atoi(av[j]);
				node->next = ft_lstnew(nbr);
				node = node->next;
				j++;
			}
		}
	}
	if(ac >= 3 && ac <= 4)
	{
		sort_3(head_a);
	}
	return(0);
}