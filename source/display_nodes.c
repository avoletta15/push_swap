/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaavoletta <mariaavoletta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:57:51 by mariaavolet       #+#    #+#             */
/*   Updated: 2023/09/11 12:03:35 by mariaavolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	display_nodes(t_list *stack)
{
	while (stack)
	{
		ft_printf("{\n");
		ft_printf("	Node's addr: %p\n", stack);
		ft_printf("	Node's value: %i\n", *(int *)stack->content);
		ft_printf("	Node's next: %p\n", stack->next);
		if (!stack->next)
			ft_printf("}\n");
		else
			ft_printf("},\n");
		stack = stack->next;
	}
}
