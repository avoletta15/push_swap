/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:31:51 by marioliv          #+#    #+#             */
/*   Updated: 2023/09/14 14:31:52 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnbr(char **av, int ac)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < ac)
	{
		if (((av[j][i] >= '-' || av[j][i] <= '+')) || \
			(av[j][i] >= '0' && av[j][i] <= '9'))
		{
			i++;
			while (av[j][i])
			{
				if (av[j][i] >= '0' && av[j][i] <= '9')
					i++;
				else
					return (1);
			}
		}
		i = 0;
		j++;
	}
	return (0);
}

int	ft_size_int(char **av, int ac)
{
	int			j;
	long long	nbr;

	j = 1;
	while (j < ac)
	{
		nbr = ft_atoll(&av[j][0]);
		if (ft_strlen(&av[j][0]) > 11)
			return (1);
		if (ft_strlen(&av[j][0]) >= 10)
		{
			if (nbr > INT_MAX || nbr < INT_MIN)
				return (1);
		}
		j++;
	}
	return (0);
}

int	ft_duplicate_nbr(char **av, int ac)
{
	int	j;
	int	i;

	j = 1;
	while (j < ac)
	{
		i = j + 1;
		while (i < ac)
		{
			if (av[i] && (ft_strncmp(av[j], av[i], 13) == 0))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_arg_protection(char **av, int ac)
{
	if (ft_isnbr(av, ac) == 1)
		return (1);
	if (ft_duplicate_nbr(av, ac) == 1)
		return (1);
	if (ft_size_int(av, ac) == 1)
		return (1);
	return (0);
}
