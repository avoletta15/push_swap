#include "push_swap.h"

/* verificar o rotate de b quando: 2 1 3 6 5 8 \ 9 12 */
void	ft_organizing_stack(t_list **origin, t_list **dest, t_moves *moves)
{
	while (moves->origin || moves->dest)
	{
		if (moves->origin > 0 && moves->dest > 0)
		{
			ft_rotate_both(origin, dest);
			moves->origin--;
			moves->dest--;
		}
		else if (moves->origin < 0 && moves->dest < 0)
		{
			ft_revrotate_both(origin, dest);
			moves->origin++;
			moves->dest++;
		}
		else
		{
			if (moves->origin > 0)
			{	
				ft_rotate_out(origin, 'a');
				moves->origin--;
			}
			if (moves->origin < 0)
			{
				ft_revrotate_out(origin, 'a');
				moves->origin++;
			}
			if (moves->dest > 0)
			{	
				ft_rotate_out(dest, 'b');
				moves->dest--;
			}
			if (moves->dest < 0)
			{
				ft_revrotate_out(dest, 'b');
				moves->dest++;
			}
		}
	}
}

void	ft_from_origin_to_dest(t_list **origin, t_list **dest, t_moves *moves, char name_stack)
{	
	// ft_printf("Moves A: %i\n", moves->origin);
	// ft_printf("Moves B: %i\n", moves->dest);
	ft_organizing_stack(origin, dest, moves);
	ft_push_out(origin, dest, name_stack);
}