#ifndef	PUSHSWAP_H
# define	PUSHSWAP_H
# include 	<stdarg.h>
# include 	<stdio.h>
# include 	<stdlib.h>
# include 	<string.h>
# include 	<unistd.h>
# include	<limits.h>
#include 	<sys/_types.h>
# include "../libft/libft.h"


/* Outputs A */
void	ft_sa(t_list **stack);
void	ft_ra(t_list **stack);
void	ft_rra(t_list **stack);

/* Outputs B */
void	ft_sb(t_list **stack);
void	ft_rb(t_list **stack);
void	ft_rrb(t_list **stack);
/* List Creation */
t_list	*new_node(char *av);

/* Input Management */
int	ft_isnbr(char **av, int ac);
int	ft_size_int(char **av, int ac);
int	ft_duplicate_nbr(char **av, int ac);
int	ft_arg_protection(char **av, int ac);

/* Checking if is Sorted */
int	get_nbr(t_list *stack_a);
int	ft_is_sorted(t_list *stack_a);

/* Sorting */
void	ft_organizing_sort_type(t_list **stack_a);
void	ft_swap(t_list **stack);
void	ft_rotate(t_list **stack);
void	ft_rev_rotate(t_list **stack);
void	ft_sorting_three(t_list **stack);

#endif