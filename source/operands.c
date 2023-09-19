/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:10:57 by marioliv          #+#    #+#             */
/*   Updated: 2023/09/19 10:42:43 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_rev_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*penultimate;
	int		i;

	i = ft_lstsize(*stack) - 1;
	temp = ft_lstlast(*stack);
	penultimate = *stack;
	while (i > 1)
	{
		penultimate = penultimate->next;
		i--;
	}
	ft_lstadd_front(stack, temp);
	penultimate->next = NULL;
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
