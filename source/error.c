#include "push_swap.h"

void	ft_error(void)
{
	ft_putendl_fd ("Error", 2);
	exit (EXIT_FAILURE);
}

void	free_function(void *content) {
    free(content);
}
