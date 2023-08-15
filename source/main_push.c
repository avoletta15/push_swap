#include "push_swap.h"


int	main(int ac, char **av)
{
	int		j;
	t_node	*node;

	j = 1;
	if(ac >= 3) /* minimun 2 numbers to sort protection */
	{
		if(ft_isnbr(av, ac) == 1) /* only numbers protection */
			return(1);
		if(ft_size_int(av, ac) == 1) /* size of an int (min or max) protection */
			return(1);
		if(ft_duplicate_nbr(av, ac) == 1) /* non duplicated numbers protection */
			return(1);
		if(ft_node_new(av[1]) != NULL) /* creating the first node of the list */
		{
			while(j < ac)
			{
				node = ft_node_new(av[j]);	
				ft_node_back(node, av[j]);
				j++;
			}
		}
	}
	return(0);
}