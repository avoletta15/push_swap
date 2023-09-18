/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:12:26 by marioliv          #+#    #+#             */
/*   Updated: 2023/09/18 17:13:12 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	back_to_a(t_list *node, t_list **stack)
{
	t_list	*position;
	t_list	*copy_stack;
	int		moves;
	int		key;

	key = 0;
	copy_stack = *stack;
	moves = 0;
	position = copy_stack;
	if (ft_head_or_tail(copy_stack, node) == 0)
	{
		key = min_in_the_stack(copy_stack);
		while (key != get_nbr(copy_stack))
			copy_stack = copy_stack->next;
		moves = ft_movements_top(copy_stack, stack);
		return (moves);
	}
	else
	{
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
	}
	moves = ft_movements_top(position, stack);
	return (moves);
}
