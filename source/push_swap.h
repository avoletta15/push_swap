#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <sys/_types.h>
# include "../libft/libft.h"

typedef struct	s_movements
{
	int		moves_a;
	int		moves_b;
}
			t_moves;
			
typedef struct	s_edges
{
	t_list		*max;
	t_list		*min;
}			t_edges;

/* Error */
void	ft_error(void);
void	free_function(void *content);

/* Outputs*/
void	ft_swap_out(t_list **stack, char name_stack);
void	ft_rotate_out(t_list **stack, char name_stack);
void	ft_rotate_both(t_list **stack_a, t_list **stack_b);
void	ft_revrotate_out(t_list **stack, char name_stack);
void	ft_revrotate_both(t_list **stack_a, t_list **stack_b);
void	ft_push_out(t_list **origin, t_list **dest, char name_stack);

/* List Creation */
t_list	*new_node(char *av);

/* Input Management */
int		ft_isnbr(char **av, int ac);
int		ft_size_int(char **av, int ac);
int		ft_duplicate_nbr(char **av, int ac);
int		ft_arg_protection(char **av, int ac);

/* Checking if is Sorted */
int		get_nbr(t_list *stack);
int		ft_sorting_checker(t_list *stack_a);

/* Operands */
void	ft_swap(t_list **stack);
void	ft_rotate(t_list **stack);
void	ft_rev_rotate(t_list **stack);
void	ft_push(t_list **origin, t_list **dest);

/* Move Cost */

int		ft_movements_top(t_list *node, t_list **stack);
int		finding_right_place(t_list *node,t_list **stack);
t_list	*ft_find_cheapest(t_list **stack_a, t_list **stack_b, t_moves *moves);
int		max_in_the_stack(t_list *stack);

/* Movements */
void	ft_organizing_stack(t_list **origin, t_list **dest, t_moves *moves);
void	ft_from_origin_to_dest(t_list **origin, t_list **dest, t_moves *moves, char name_stack);
/* Sorting */
void	ft_choosing_sort_method(t_list **stack_a);
void	ft_sorting_three(t_list **stack, char name_stack);
void	ft_sorting_larger_stack(t_list **stack_a, t_list **stack_b);


// Test
void	display_nodes(t_list *stack);
// Test
#endif