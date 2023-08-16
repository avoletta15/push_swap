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



/* Stack Node Struct */

/* Input Management */
int	ft_isnbr(char **av, int ac);
int	ft_size_int(char **av, int ac);
int	ft_duplicate_nbr(char **av, int ac);
int	ft_arg_protection(char **av, int ac);

/* Sorting */
void	sort_3(t_list **head);

#endif