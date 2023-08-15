#include "push_swap.h"


int	main(int ac, char **av)
{
	t_node	*node = ft_calloc(1, sizeof (t_node));

	if(ac >= 3) /* minimun 2 numbers to sort protection */
	{
		if(ft_isnbr(av, ac) == 1) /* only numbers protection */
			return(1);
		if(ft_size_int(av, ac) == 1) /* size of an int (min or max) protection */
			return(1);
		if(ft_duplicates(av, ac) == 1) /* non duplicated numbers protection */
			return(1);
		if(ft_node_new == 0) /* creating the first node of the list */
		{

		}
	}
	return(0);
}

