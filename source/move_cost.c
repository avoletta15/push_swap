/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:31:59 by marioliv          #+#    #+#             */
/*   Updated: 2023/09/19 11:46:41 by marioliv         ###   ########.fr       */
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
	int		moves;
	int		key;

	key = 0;
	copy_stack = *stack;
	moves = 0;
	if (ft_head_or_tail(copy_stack, node) == 0)
		return (allocating_edges_go(copy_stack, stack, key, moves));
	moves = ft_movements_top(allocating_others(copy_stack,
				node, stack), stack);
	return (moves);
}

int	rotation_cost(int origin_moves, int dest_moves)
{
	int	moves;

	moves = 0;
	if (origin_moves > 0 && dest_moves > 0)
		moves = positive_cost(origin_moves, dest_moves);
	else if (origin_moves < 0 && dest_moves < 0)
		moves = negative_cost(origin_moves, dest_moves);
	else
	{
		if (origin_moves < 0)
			moves = (-1 * origin_moves) + dest_moves;
		else if (dest_moves < 0)
			moves = origin_moves + (-1 * dest_moves);
		else
			return (origin_moves + dest_moves);
	}
	return (moves);
}

t_list	*ft_find_cheapest(t_list **stack_a, t_list **stack_b, t_moves *moves)
{
	t_list	*copy_stack;
	t_list	*cheapest;
	int		origin_moves;
	int		dest_moves;
	int		total_moves_before;

	copy_stack = *stack_a;
	cheapest = copy_stack;
	total_moves_before = INT_MAX;
	while (copy_stack)
	{
		origin_moves = ft_movements_top(copy_stack, stack_a);
		dest_moves = finding_right_place(copy_stack, stack_b);
		moves->total_moves = rotation_cost(origin_moves, dest_moves);
		if (moves->total_moves < total_moves_before)
		{
			cheapest = copy_stack;
			moves->origin = origin_moves;
			moves->dest = dest_moves;
			total_moves_before = moves->total_moves;
		}
		(copy_stack) = (copy_stack)->next;
	}
	return (cheapest);
}
