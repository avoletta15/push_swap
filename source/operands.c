#include "push_swap.h"

/**************************************************************
* saving the begining of the list                             *
* syaing that the begining of the list is now the second node *
* sayng that the begining of the string now points to NULL    *
* saying that the second node is now the former first node    *
***************************************************************/
void	ft_swap(t_list **stack)
{
	t_list	*temp;

	temp = *stack; 
	*stack = (*stack)->next; 
	temp->next = temp->next->next; 
	(*stack)->next = temp;
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
}

/* free_matrix(stack_temp) acima*/

void	ft_rev_rotate(t_list **stack)
{
	t_list	*temp;

	temp = ft_lstlast(*stack);
	ft_lstadd_front(stack, temp);
}

void	ft_push(t_list **origin, t_list **dest)
{
	t_list	*temp;

	if (origin == NULL || *origin == NULL)
		return ;
	temp = (*origin)->next;
	(*origin)->next = (*dest);
	*dest = *origin;
	(*origin) = (*origin)->next;
	*origin = temp;
}