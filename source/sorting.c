#include "push_swap.h"

void	ft_organizing_sort_method(t_list **stack_a)
{
	/* t_list	*stack_b;

	stack_b = NULL; */
	if (ft_lstsize(*stack_a) == 2)
		ft_swap_out(stack_a, 'a');
	else if (ft_lstsize(*stack_a) == 3)
		ft_sorting_three(stack_a, 'a');
}

void	ft_sorting_three(t_list **stack, char name_stack)
{
	if (get_nbr(*stack) > get_nbr((*stack)->next) \
		&& get_nbr(*stack) > get_nbr((*stack)->next->next))
	{
		if (get_nbr((*stack)->next) > get_nbr((*stack)->next->next))
		{
			ft_rotate_out(stack, name_stack);
			ft_swap_out(stack, name_stack);
		}
		else
			ft_rotate_out(stack, name_stack);
		return ;
	}
	else if ((get_nbr(*stack) > get_nbr((*stack)->next) && \
			get_nbr(*stack) < get_nbr((*stack)->next->next)) \
			|| (get_nbr(*stack) < get_nbr((*stack)->next) && \
			get_nbr(*stack) > get_nbr((*stack)->next->next)))
	{
		if (get_nbr(*stack) > get_nbr((*stack)->next))
			ft_swap_out(stack, name_stack);
		else if (get_nbr(*stack) < get_nbr((*stack)->next))
			ft_revrotate_out(stack, name_stack);
		return ;
	}
	else
	{
		ft_revrotate_out(stack, name_stack);
		ft_swap_out(stack, name_stack);
	}
}

void	ft_sorting_larger_stack(t_list **stack_a, t_list **stack_b)
{
	ft_push_out(stack_a, stack_b, 'b');
	ft_push_out(stack_a, stack_b, 'b');

}

void	ft_find_cheapest(t_list **stack_a, t_list **stack_b)
{
	t_list *cheapest;

}

int	ft_movements_top(t_list *node, t_list **stack_a)
{
	int	push_back;
	int	pull_front;

	while (node != (&stack_a))
	{
		(*stack_a) = (*stack_a)->next;
		push_back++;
	}
	while (node)
	{
		node = node->next;
		pull_front++;
	}
	if(push_back <= pull_front)
		return(push_back);
	else
		return(pull_front);
}

void	ft_organizing_dest_to_recieve(t_list *cheapest,t_list **stack_b, char haed_tail)
{
	if (haed_tail == 'h')
	{
		/*
		put max to the top
		push cheapest to stack_b
		 */
	}
	else if (haed_tail == 't')
	{
		/*
		put min to the tail
		push cheapest to stack_b
		push cheapest to tail 
		 */
	}
}

void	finding_right_place(t_list *cheapest,t_list **stack)
{
	t_list **head;
	t_list *max;
	t_list *min;

	*head == *stack;
	while(head)
	{
		if(get_nbr(*head) < get_nbr((*head)->next))
			max = (*head);
		if(get_nbr(*head) > get_nbr((*head)->next))
			min = (*head);
		(*head) = (*head)->next;
	}
	if (get_nbr(cheapest) > get_nbr(max))
		/* max tem que ser o head e ai push cheapest */
	else if(get_nbr(cheapest) < get_nbr(min))
		/* cheapest tem que ser o -> NULL */
}