#include "push_swap.h"

/* verificar o rotate de b quando: 2 1 3 6 5 8 \ 9 12 */
void	ft_organizing_stack(t_list **origin, t_list **dest, t_moves *moves)
{
	while (moves->moves_a || moves->moves_b)
	{
		printf("INSIDE\n");
		if (moves->moves_a > 0 && moves->moves_b > 0)
		{
			ft_revrotate_both(origin, dest);
			moves->moves_a--;
			moves->moves_b--;
		}
		else if (moves->moves_a < 0 && moves->moves_b < 0)
		{
			ft_revrotate_both(origin, dest);
			moves->moves_a++;
			moves->moves_b++;
		}
		else
		{
			if (moves->moves_a > 0)
			{	
				ft_rotate_out(origin, 'a');
				moves->moves_a--;
			}
			if (moves->moves_a < 0)
			{
				ft_revrotate_out(origin, 'a');
				moves->moves_a++;
			}
			if (moves->moves_b > 0)
			{	
				ft_rotate_out(dest, 'b');
				moves->moves_b--;
			}
			if (moves->moves_b < 0)
			{
				ft_revrotate_out(dest, 'b');
				moves->moves_b--;
			}
		}
	}
}

void	ft_from_origin_to_dest(t_list **origin, t_list **dest, t_moves *moves, char name_stack)
{	
	// printf("Moves Origin: %d\n", moves->moves_a);
	// printf("Moves Dest: %d\n", moves->moves_b);
	ft_organizing_stack(origin, dest, moves);
	ft_push_out(origin, dest, name_stack);
}