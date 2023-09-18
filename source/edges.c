/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:42:11 by marioliv          #+#    #+#             */
/*   Updated: 2023/09/18 17:05:26 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_in_the_stack(t_list *stack)
{
	int	nbr;

	nbr = get_nbr(stack);
	while (stack)
	{
		if (get_nbr(stack) > nbr)
			nbr = get_nbr(stack);
		stack = stack->next;
	}
	return (nbr);
}

int	min_in_the_stack(t_list *stack)
{
	int	nbr;

	nbr = get_nbr(stack);
	while (stack)
	{
		if (get_nbr(stack) < nbr)
			nbr = get_nbr(stack);
		stack = stack->next;
	}
	return (nbr);
}

int	ft_head_or_tail(t_list *stack, t_list *node)
{
	if ((get_nbr(node) > max_in_the_stack(stack))
		|| get_nbr(node) < min_in_the_stack(stack))
		return (0);
	return (1);
}
