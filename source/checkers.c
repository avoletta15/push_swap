/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:30:43 by marioliv          #+#    #+#             */
/*   Updated: 2023/09/19 09:35:11 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nbr(t_list *stack)
{
	return (*(int *)(stack->content));
}

int	ft_is_sorted_head_tail(t_list *stack)
{
	int	i;

	i = get_nbr(stack);
	while (stack)
	{
		if (i > get_nbr(stack))
			return (1);
		i = get_nbr(stack);
		stack = stack->next;
	}
	return (0);
}

int	ft_sorting_tail_head(t_list *stack)
{
	int	i;

	i = get_nbr(stack);
	while (stack)
	{
		if (i < get_nbr(stack))
			return (1);
		i = get_nbr(stack);
		stack = stack->next;
	}
	return (0);
}

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	free_function(void *content)
{
	free(content);
}
