/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 02:10:50 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/18 03:11:37 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	(void)a;
	if (ft_stack_size(*b) < 2)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_add_back(b, tmp);
	ft_putstr_fd("rb\n", 1);
}

// (rr) ra and rb at the same time.
void	rr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (ft_stack_size(*a) < 2)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_add_back(a, tmp);
	if (ft_stack_size(*b) < 2)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_add_back(b, tmp);
	ft_putstr_fd("rr\n", 1);
}

// (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	(void)b;
	if (ft_stack_size(*a) < 2)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *a;
	*a = tmp->next;
	tmp->next = NULL;
	ft_putstr_fd("rra\n", 1);
}

// (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	(void)a;
	if (ft_stack_size(*b) < 2)
		return ;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *b;
	*b = tmp->next;
	tmp->next = NULL;
	ft_putstr_fd("rrb\n", 1);
}

// rra and rrb at the same time.
void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (ft_stack_size(*a) < 2)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *a;
	*a = tmp->next;
	tmp->next = NULL;
	if (ft_stack_size(*b) < 2)
		return ;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *b;
	*b = tmp->next;
	tmp->next = NULL;
	ft_putstr_fd("rrr\n", 1);
}
