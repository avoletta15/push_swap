/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:11:38 by marioliv          #+#    #+#             */
/*   Updated: 2023/09/19 11:41:34 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_movements
{
	int		origin;
	int		dest;
	int		total_moves;
	char	dest_char;
	char	origin_char;
}			t_moves;

typedef struct s_edges
{
	t_list	*max;
	t_list	*min;
}			t_edges;

/* Checker */
int			get_nbr(t_list *stack);
int			ft_is_sorted_head_tail(t_list *stack);
int			ft_sorting_tail_head(t_list *stack);
void		ft_error(void);
void		free_function(void *content);

/* Edges */
int			max_in_the_stack(t_list *stack);
int			min_in_the_stack(t_list *stack);
int			ft_head_or_tail(t_list *stack, t_list *node);
int			allocating_edges_go(t_list *copy_stack, t_list **stack, int key,
				int moves);
int			allocating_edges_back(t_list *copy_stack, t_list **stack);

/* Input Management */
int			ft_isnbr(char **av, int ac);
int			ft_size_int(char **av, int ac);
int			ft_duplicate_nbr(char **av, int ac);
int			ft_arg_protection(char **av, int ac);

/* Midle */
t_list		*allocating_others(t_list *copy_stack, t_list *node,
				t_list **stack);
int			negative_cost(int origin_moves, int dest_moves);
int			positive_cost(int origin_moves, int dest_moves);
t_list		*allocating_others_back(t_list *copy_stack, t_list *node,
				t_list **stack);

/* Move Cost */
int			ft_movements_top(t_list *node, t_list **stack);
int			finding_right_place(t_list *node, t_list **stack);
int			rotation_cost(int origin_moves, int dest_moves);
t_list		*ft_find_cheapest(t_list **stack_a, t_list **stack_b,
				t_moves *moves);
/* Movements */
void		ft_organizing_stack(t_list **origin, t_list **dest, t_moves *moves);
void		ft_organizing_when_different(t_list **origin, t_list **dest,
				t_moves *moves);
void		ft_from_origin_to_dest(t_list **origin, t_list **dest,
				t_moves *moves, char name_stack);
int			back_to_a(t_list *node, t_list **stack);

/* Operands */
void		ft_swap(t_list **stack);
void		ft_rotate(t_list **stack);
void		ft_rev_rotate(t_list **stack);
void		ft_push(t_list **origin, t_list **dest);

/* Rotate & Reverse Rotate */
void		ft_rotate_out(t_list **stack, char name_stack);
void		ft_rotate_both(t_list **stack_a, t_list **stack_b);
void		ft_revrotate_out(t_list **stack, char name_stack);
void		ft_revrotate_both(t_list **stack_a, t_list **stack_b);

/*Swap & Push*/
void		ft_swap_out(t_list **stack, char name_stack);
void		ft_push_out(t_list **origin, t_list **dest, char name_stack);

/* List Creation */
t_list		*new_node(char *av);

/* Sorting */
void		ft_choosing_sort_method(t_list **stack_a);
void		begins_with_bigger(t_list **stack, char name_stack);
void		ft_sorting_three(t_list **stack, char name_stack);
void		ft_sorting_larger_stack_go(t_list **stack_a, t_list **stack_b);
void		ft_sorting_larger_stack_back(t_list **stack_a, t_list **stack_b,
				t_moves *moves);

#endif