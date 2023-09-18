/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:08:09 by marioliv          #+#    #+#             */
/*   Updated: 2023/09/18 17:08:21 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	}
}

void	ft_from_origin_to_dest(t_list **origin, t_list **dest, t_moves *moves,
		char name_stack)
{
	ft_organizing_stack(origin, dest, moves);
	ft_push_out(origin, dest, name_stack);
}
