#include "push_swap.h"

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if(ac >= 3) /* minimun 2 numbers to sort protection */
	{
		if(ft_isnbr(av, ac) == 1) /* only numbers protection */
			return(1);
		if(ft_size_int(av, ac) == 1) /* size of an int (min or max) protection*/
			return(1);
		if(ft_duplicates(av, ac) == 1) /* non duplicated numbers protection */
			return(1);
	}
	return(0);
}

// int	main(int ac, char **av)
// {
// 	ft_printf("RESULT: %i\n", ft_duplicates(av, ac));
// 	return(0);
// }
