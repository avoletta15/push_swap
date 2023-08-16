#include "push_swap.h"

int	ft_isnbr(char **av, int ac)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < ac)
	{
		// if(!av[j][i] || av[j][i] == '\0')
		// {	
		// 	ft_putendl_fd("Error", 2);
		// 	return(1);
		// }
		if(((av[j][i] >= '-' || av[j][i] <= '+')) || (av[j][i] >= '0' && av[j][i] <= '9'))
		{
			i++;
			while(av[j][i])
			{
				if(av[j][i] >= '0' && av[j][i] <= '9')
					i++;
				else
				{	
					ft_putendl_fd("Error", 2);
					return(1);
				}
			}
		}
		i = 0;
		j++;
	}
	return(0);
}

int	ft_size_int(char **av, int ac)
{
	int	j;
	
	j = 1;
	while(j < ac)
	{
		if (ft_strlen(&av[j][0]) == 10)
		{	
			if((av[j][0] >= '3' && av[j][0] <= '9') || ((ft_strncmp("214748364", &av[j][0], 9) == 0) && (av[j][9] == '8' || av[j][9] == '9')))
			{
				ft_putendl_fd("Error", 2);
				return(1);
			}
		}
		else if(ft_strlen(&av[j][0]) == 11)
		{
			if(((ft_strncmp("-214748364", &av[j][0], 10) == 0) && (av[j][9] == '9')) || (av[j][1] >= '3' && av[j][0] <= '9'))
			{
				ft_putendl_fd("Error", 2);
				return(1);
			}
		}
		j++;
	}
	return(0);
}

int	ft_duplicate_nbr(char **av, int ac)
{
	int	j;
	int i;

	j = 1;
	while(j < ac)
	{
		i = j + 1;
		while (i < ac)
		{
			if(av[i] && (ft_strncmp(av[j], av[i], 13) == 0))
				return (1);
			i++;
		}
		j++;
	}
	return(0);
}
