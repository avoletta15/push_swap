#include "push_swap.h"

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