/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:57:51 by mariaavolet       #+#    #+#             */
/*   Updated: 2023/09/13 17:30:45 by marioliv         ###   ########.fr       */
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
