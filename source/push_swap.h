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



/* List Creation */
t_list	*new_node(char *av);

/* Input Management */
int	ft_isnbr(char **av, int ac);
int	ft_size_int(char **av, int ac);
int	ft_duplicate_nbr(char **av, int ac);
int	ft_arg_protection(char **av, int ac);

/* Sorting */
int	get_nbr(t_list *stack_a);
int	ft_is_sorted(t_list *stack_a);

#endif