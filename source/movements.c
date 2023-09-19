/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:08:09 by marioliv          #+#    #+#             */
/*   Updated: 2023/09/19 10:46:01 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_organizing_when_different(t_list **origin,
		t_list **dest, t_moves *moves)
{
	if (moves->origin > 0)
	{
		ft_rotate_out (origin, moves->origin_char);
		moves->origin--;
	}
	if (moves->origin < 0)
	{
		ft_revrotate_out (origin, moves->origin_char);
		moves->origin++;
	}
	if (moves->dest > 0)
	{
		ft_rotate_out (dest, moves->dest_char);
		moves->dest--;
	}
	if (moves->dest < 0)
	{
		ft_revrotate_out (dest, moves->dest_char);
		moves->dest++;
	}
}

void	ft_organizing_stack(t_list **origin, t_list **dest, t_moves *moves)
{
	while (moves->origin || moves->dest)
	{
		if (moves->origin > 0 && moves->dest > 0)
		{
			ft_rotate_both (origin, dest);
			moves->origin--;
			moves->dest--;
		}
		else if (moves->origin < 0 && moves->dest < 0)
		{
			ft_revrotate_both (origin, dest);
			moves->origin++;
			moves->dest++;
		}
		else
			ft_organizing_when_different(origin, dest, moves);
	}
}

void	ft_from_origin_to_dest(t_list **origin, t_list **dest, t_moves *moves,
		char name_stack)
{
	ft_organizing_stack(origin, dest, moves);
	ft_push_out(origin, dest, name_stack);
}

int	back_to_a(t_list *node, t_list **stack)
{
	t_list	*copy_stack;
	int		moves;

	copy_stack = *stack;
	moves = 0;
	if (ft_head_or_tail(copy_stack, node) == 0)
		return (allocating_edges_back(copy_stack, stack));
	moves = ft_movements_top(allocating_others_back(copy_stack,
				node, stack), stack);
	return (moves);
}
