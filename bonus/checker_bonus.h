/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:10:36 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/18 05:19:08 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
#define CHECKER_BONUS_H
#include "../srcs/libft/libft.h"
#include "get_next_line_bonus.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int		is_stack_sorted(t_stack *stack);
t_stack	*ft_nb_new(int nb);
void	ft_clear_stack(t_stack **lst);
void	ft_add_back(t_stack **lst, t_stack *new);
t_stack	*check_args(int ac, char **av);
int		ft_stack_size(t_stack *stack);
int		is_int(char *str);
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
#endif