/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:31:59 by marioliv          #+#    #+#             */
/*   Updated: 2023/09/18 17:09:54 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_movements_top(t_list *node, t_list **stack)
{
	t_list	*copy_stack;
	int		push_back;
	int		pull_front;

	copy_stack = *stack;
	pull_front = 0;
	push_back = 0;
	while (node != (copy_stack))
	{
		(copy_stack) = (copy_stack)->next;
		push_back++;
	}
	while (node)
	{
		node = node->next;
		pull_front++;
	}
	if (push_back < pull_front)
		return (push_back);
	else
		return (-(pull_front));
}

int	finding_right_place(t_list *node, t_list **stack)
{
	t_list	*copy_stack;
	t_list	*position;
	int		moves;
	int		key;

	key = 0;
	copy_stack = *stack;
	moves = 0;
	position = copy_stack;
	if (ft_head_or_tail(copy_stack, node) == 0)
	{
		key = max_in_the_stack(copy_stack);
		while (key != get_nbr(copy_stack))
			copy_stack = copy_stack->next;
		moves = ft_movements_top(copy_stack, stack);
		return (moves);
	}
	else
	{
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
	}
	moves = ft_movements_top(position, stack);
	return (moves);
}

int	rotation_cost(int origin_moves, int dest_moves)
{
	int	total_moves;

	total_moves = 0;
	if (origin_moves > 0 && dest_moves > 0)
	{
		if (origin_moves > dest_moves)
			total_moves = origin_moves;
		else
			total_moves = dest_moves;
	}
	else if (origin_moves < 0 && dest_moves < 0)
	{
		if (origin_moves < dest_moves)
			total_moves = -1 * (origin_moves);
		else
			total_moves = -1 * (dest_moves);
	}
	else
	{
		if (origin_moves <= 0)
			total_moves = (-1 * origin_moves) + dest_moves;
		else
			total_moves = origin_moves + (-1 * dest_moves);
	}
	return (total_moves);
}

t_list	*ft_find_cheapest(t_list **stack_a, t_list **stack_b, t_moves *moves)
{
	t_list	*copy_stack;
	t_list	*cheapest;
	int		origin_moves;
	int		dest_moves;
	int		total_moves;
	int		total_moves_before;

	copy_stack = *stack_a;
	cheapest = copy_stack;
	total_moves_before = INT_MAX;
	while (copy_stack)
	{
		origin_moves = ft_movements_top(copy_stack, stack_a);
		dest_moves = finding_right_place(copy_stack, stack_b);
		total_moves = rotation_cost(origin_moves, dest_moves);
		if (total_moves < total_moves_before)
		{
			cheapest = copy_stack;
			moves->origin = origin_moves;
			moves->dest = dest_moves;
			total_moves_before = total_moves;
		}
		(copy_stack) = (copy_stack)->next;
	}
	return (cheapest);
}
