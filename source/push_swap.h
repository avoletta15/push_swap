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

typedef	struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}					t_node;

/* Input Management */
int		ft_isnbr(char **av, int ac);
int		ft_size_int(char **av, int ac);
int		ft_duplicate_nbr(char **av, int ac);
int		ft_node_new(char *av);
void	ft_fill_stack(char **av, int ac, t_node *node);

#endif