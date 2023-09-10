#include "push_swap.h"

// void	ft_filling_b(t_list *cheapest, t_list **stack_a, t_list **stack_b, t_moves moves)
// {
// 	while (stack_a || stack_b)
// 	{
// 		if (moves.moves_a > 0 && moves.moves_b > 0)
// 		{
// 			ft_revrotate_both(stack_a, stack_b);
// 			moves.moves_a--;
// 			moves.moves_b--;
// 		}
// 		else if (moves.moves_a < 0 && moves.moves_b < 0)
// 		{
// 			ft_revrotate_both(stack_a, stack_b);
// 			moves.moves_a++;
// 			moves.moves_b++;
// 		}
// 		else
// 		{
// 			if (moves.moves_a > 0)
// 				ft_rotate_out(stack_a, 'a');
// 			else if (moves.moves_a < 0)
// 				ft_rev_rotate_out(stack_a, 'a');
// 			if (moves.moves_b > 0)
// 				ft_rotate_out(stack_a, 'b');
// 			else if (moves.moves_b < 0)
// 				ft_rev_rotate_out(stack_a, 'b');	
// 		}
// 	}
// }

// void	ft_from_a_to_b(t_list **stack_a, t_list **stack_b, t_list *cheapest, t_moves *moves)
// {
		
// 		ft_filling_b(cheapest, stack_a, stack_b, moves);
// 		ft_push_out(stack_a, stack_b, 'b');
// }