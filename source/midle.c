/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:38:19 by marioliv          #+#    #+#             */
/*   Updated: 2023/09/19 11:06:03 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*allocating_others(t_list *copy_stack, t_list *node, t_list **stack)
{
	t_list	*position;

	position = copy_stack;
	while (copy_stack)
	{
		if (get_nbr((copy_stack)) > get_nbr(node))
		{
			if (copy_stack->next
				&& get_nbr(copy_stack->next) < get_nbr(node))
			{
				position = copy_stack->next;
				break ;
			}
			else if ((copy_stack->next == NULL)
				&& get_nbr(*stack) < get_nbr(node))
			{
				position = *stack;
				break ;
			}
		}
		(copy_stack) = (copy_stack)->next;
	}
	return (position);
}

int	positive_cost(int origin_moves, int dest_moves)
{
	if (origin_moves > dest_moves)
		return (origin_moves);
	else
		return (dest_moves);
}

int	negative_cost(int origin_moves, int dest_moves)
{
	if (origin_moves < dest_moves)
		return (-1 * (origin_moves));
	else
		return (-1 * (dest_moves));
}

t_list	*allocating_others_back(t_list *copy_stack, t_list *node,
		t_list **stack)
{
	t_list	*position;

	position = copy_stack;
	while (copy_stack)
	{
		if (get_nbr((copy_stack)) < get_nbr(node))
		{
			if (copy_stack->next
				&& get_nbr(copy_stack->next) > get_nbr(node))
			{
				position = copy_stack->next;
				break ;
			}
			else if ((copy_stack->next == NULL)
				&& get_nbr(*stack) > get_nbr(node))
			{
				position = *stack;
				break ;
			}
		}
		(copy_stack) = (copy_stack)->next;
	}
	return (position);
}
