/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:50:40 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/18 03:02:10 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "srcs/libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_sorted
{
	int				*sorted_array;
	int				start;
	int				end;
}					t_sorted;

t_stack				*check_args(int ac, char **av);
int					is_int(char *str);
void				ft_print_list(t_stack *lst);
void				ft_clear_stack(t_stack **lst);
void				ft_add_back(t_stack **lst, t_stack *new);
t_stack				*ft_nb_new(int nb);
int					ft_stack_size(t_stack *stack);
int					is_stack_sorted(t_stack *stack);
void				sa(t_stack **a, t_stack **b);
void				sb(t_stack **a, t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a, t_stack **b);
void				rb(t_stack **a, t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a, t_stack **b);
void				rrb(t_stack **a, t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				sort_three(t_stack **a, t_stack **b);
void				sort_four(t_stack **a, t_stack **b);
void				sort_five(t_stack **a, t_stack **b);
void				sort(t_stack **a, t_stack **b, int size);
// sort utils
int					get_chunk_size(int stack_size);
void				sort_int_tab(int *tab, int size);
int					*stack_to_array(t_stack *a, int size);
int					ft_stack_last(t_stack *stack);
int					ft_find_max(t_stack *stack);
#endif