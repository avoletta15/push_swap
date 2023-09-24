/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:31:51 by marioliv          #+#    #+#             */
/*   Updated: 2023/09/24 15:58:16 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnbr(char **av, int ac)
{
	static int	i;
	static int	j;

	while (++j < ac)
	{
		if (!av[j][0])
			return (1);
		if ((av[j][i] == '-' || av[j][i] == '+')
			&& (ft_isdigit(av[j][i + 1]) == 0))
			return (1);
		else 
		{
			if (av[j][i] == '-' || av[j][i] == '+')
				i++;
			while (av[j][i])
			{
				if (!(av[j][i] >= '0' && av[j][i] <= '9'))
					return (1);
				i++;
			}
		}
		i = 0;
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
		j++;
	}
	return (0);
}

int	ft_duplicate_nbr(t_list **stack)
{
	t_list	*copy_stack;
	t_list	*start;
	int		i;

	i = 1;
	copy_stack = (*stack)->next;
	start = *stack;
	while (start != NULL && copy_stack != NULL)
	{
		if (get_nbr(start) == get_nbr(copy_stack))
			return (1);
		else if (copy_stack->next == NULL)
		{
			copy_stack = start->next->next;
			start = start->next;
		}
		else
			copy_stack = copy_stack->next;
	}
	return (0);
}

int	ft_arg_protection(char **av, int ac)
{
	if (ft_isnbr(av, ac) == 1)
		return (1);
	if (ft_size_int(av, ac) == 1)
		return (1);
	return (0);
}
