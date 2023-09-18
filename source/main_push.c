/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:26:08 by marioliv          #+#    #+#             */
/*   Updated: 2023/09/14 15:51:01 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			node = new_node(av[j++]);
			if (node)
				ft_lstadd_back(&stack_a, node);
			else
				ft_error ();
		}
	}
	else
		ft_error ();
	if (ft_is_sorted_head_tail(stack_a) == 1)
		ft_choosing_sort_method (&stack_a);
	ft_lstclear(&stack_a, free_function);
	return (0);
}
