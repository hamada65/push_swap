/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:50:40 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/14 01:34:47 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct	s_stack
{
	int				data;
	int				chunk;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

t_stack	*check_args(int ac, char **av);
int is_int(char *str);
void ft_print_list(t_stack *lst);
void	ft_clear_stack(t_stack **lst);
void	ft_add_back(t_stack **lst, t_stack *new);
int		ft_stack_size(t_stack *stack);
void	sa(t_stack **a, t_stack **b);
void	sb(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, t_stack **b);
void	rrb(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sort_three(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
int	is_stack_sorted(t_stack *stack);