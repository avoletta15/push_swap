#include "push_swap.h"

void	ft_filling_b(t_list **stack_a, t_list **stack_b, t_moves *moves)
{
	while (moves->moves_a || moves->moves_b)
	{
		if (moves->moves_a > 0 && moves->moves_b > 0)
		{
			ft_revrotate_both(stack_a, stack_b);
			moves->moves_a--;
			moves->moves_b--;
		}
		else if (moves->moves_a < 0 && moves->moves_b < 0)
		{
			ft_revrotate_both(stack_a, stack_b);
			moves->moves_a++;
			moves->moves_b++;
		}
		else
		{
			if (moves->moves_a > 0)
			{	
				ft_rotate_out(stack_a, 'a');
				moves->moves_a--;
			}
			if (moves->moves_a < 0)
			{
				ft_revrotate_out(stack_a, 'a');
				moves->moves_a++;
			}
			if (moves->moves_b > 0)
			{	
				ft_rotate_out(stack_b, 'b');
				moves->moves_b--;
			}
			if (moves->moves_b < 0)
			{
				ft_revrotate_out(stack_b, 'b');
				moves->moves_b--;
			}
		}
	}
}

void	ft_from_a_to_b(t_list **stack_a, t_list **stack_b, t_moves *moves)
{
		printf("Moves A: %d\n", moves->moves_a);		
		printf("Moves B: %d\n", moves->moves_b);		
		ft_filling_b(stack_a, stack_b, moves);
		ft_push_out(stack_a, stack_b, 'b');
}