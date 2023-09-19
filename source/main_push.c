/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:26:08 by marioliv          #+#    #+#             */
/*   Updated: 2023/09/19 11:51:50 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_nodes(t_list *stack)
{
	while (stack)
	{
		ft_printf("{\n");
		ft_printf("	Node's nbr: %i\n", *(int *)stack->content);
		if (!stack->next)
			ft_printf("}\n");
		else
			ft_printf("},\n");
		stack = stack->next;
	}
} 

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
	// display_nodes(stack_a);
	ft_lstclear(&stack_a, free_function);
	return (0);
}
