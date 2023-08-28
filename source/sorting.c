#include "push_swap.h"

void	ft_organizing_sort_type(t_list **stack_a)
{
	// t_list	*stack_b;

	// stack_b = NULL;
	if(ft_lstsize(*stack_a) == 2)
		ft_swap(stack_a);
	if(ft_lstsize(*stack_a) == 3)
		ft_sorting_three(stack_a);

}

void	ft_swap(t_list **stack)
{
	t_list	*temp;
	
	temp = *stack; /* saving the begining of the list */
	*stack = (*stack)->next; /* syaing that the begining of the list is now the second node */
	temp->next = temp->next->next; /* sayng that the begining of the string now points to NULL */
	(*stack)->next = temp; /* saying that the second node is now the former first node */
}

void	ft_rotate(t_list **stack)
{
	t_list	*first;
	t_list	**stack_temp;

	stack_temp = stack;
	first = *stack_temp;
	*stack_temp = (*stack_temp)->next;
	first->next = NULL;
	ft_lstadd_back(stack, first);
	/* free_matrix(stack_temp) */
}

void	ft_rev_rotate(t_list **stack)
{
	t_list	*temp;

	temp = ft_lstlast(*stack);
	ft_lstadd_front(stack, temp);
}

void	ft_sorting_three(t_list **stack)
{
	if(get_nbr(*stack) > get_nbr((*stack)->next) && get_nbr(*stack) > get_nbr((*stack)->next->next))
	{
		if(get_nbr((*stack)->next) > get_nbr((*stack)->next->next))
		{
			ft_rotate(stack);
			ft_swap(stack);
			ft_printf("ra\nsa\n");
		}
		else
		{
			ft_rotate(stack);
			ft_putendl_fd("ra", 1);
		}
		return ;
	}
	else if((get_nbr(*stack) > get_nbr((*stack)->next) && get_nbr(*stack) < get_nbr((*stack)->next->next)) \
			|| (get_nbr(*stack) < get_nbr((*stack)->next) && get_nbr(*stack) > get_nbr((*stack)->next->next)))
	{
		if(get_nbr(*stack) > get_nbr((*stack)->next))
		{
			ft_swap(stack);
			ft_putendl_fd("sa", 1);
		}
		else if(get_nbr(*stack) < get_nbr((*stack)->next))
		{
			ft_rev_rotate(stack);
			ft_putendl_fd("rra", 1);
		}
		return ;
	}
	else
	{
		ft_rev_rotate(stack);
		ft_swap(stack);
		ft_printf("rra\nsa\n");
	}
}

