/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:02:01 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/16 20:57:44 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	int	num;

	num = 0;
	while (stack)
	{
		stack = stack->next;
		num++;
	}
	return (num);
}

// (swap a) Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	sa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	(void)b;
	if (ft_stack_size(*a) < 2)
		return ;
	tmp = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	tmp->prev = *a;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	ft_putstr_fd("sa\n", 1);
}

// (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	(void)a;
	if (ft_stack_size(*b) < 2)
		return ;
	tmp = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	tmp->prev = *b;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	ft_putstr_fd("sb\n", 1);
}

// (ss) sa and sb at the same time.

void	ss(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (ft_stack_size(*a) < 2)
		return ;
	tmp = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	tmp->prev = *a;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (ft_stack_size(*b) < 2)
		return ;
	tmp = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	tmp->prev = *b;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	ft_putstr_fd("ss\n", 1);
}

// (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = *a;
	tmp->prev = NULL;
	*a = tmp;
	if ((*a)->next)
		(*a)->next->prev = *a;
	ft_putstr_fd("pa\n", 1);
}

// (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = *b;
	tmp->prev = NULL;
	*b = tmp;
	if ((*b)->next)
		(*b)->next->prev = *b;
	ft_putstr_fd("pb\n", 1);
}

// (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.

void	ra(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	(void)b;
	if (ft_stack_size(*a) < 2)
		return ;
	tmp = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	tmp->prev = NULL;
	tmp->next = NULL;
	ft_add_back(a, tmp);
	ft_putstr_fd("ra\n", 1);
}

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
	(*b)->prev = NULL;
	tmp->prev = NULL;
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
	(*a)->prev = NULL;
	tmp->prev = NULL;
	tmp->next = NULL;
	ft_add_back(a, tmp);
	if (ft_stack_size(*b) < 2)
		return ;
	tmp = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	tmp->prev = NULL;
	tmp->next = NULL;
	ft_add_back(b, tmp);
	ft_putstr_fd("rr\n", 1);
}

// (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*second_last;

	(void)b;
	if (ft_stack_size(*a) < 2)
		return ;
	tmp = *a;
	while (tmp->next)
	{
		second_last = tmp;
		tmp = tmp->next;
	}
	second_last->next = NULL;
	tmp->prev = NULL;
	tmp->next = *a;
	(*a)->prev = tmp;
	*a = tmp;
	ft_putstr_fd("rra\n", 1);
}

// (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*second_last;

	(void)a;
	if (ft_stack_size(*b) < 2)
		return ;
	tmp = *b;
	while (tmp->next)
	{
		second_last = tmp;
		tmp = tmp->next;
	}
	second_last->next = NULL;
	tmp->prev = NULL;
	tmp->next = *b;
	(*b)->prev = tmp;
	*b = tmp;
	ft_putstr_fd("rrb\n", 1);
}

// rra and rrb at the same time.
void	rrr(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	t_stack *second_last;

	if (ft_stack_size(*a) < 2)
		return ;
	tmp = *a;
	while (tmp->next)
	{
		second_last = tmp;
		tmp = tmp->next;
	}
	second_last->next = NULL;
	tmp->prev = NULL;
	tmp->next = *a;
	(*a)->prev = tmp;
	*a = tmp;
	if (ft_stack_size(*b) < 2)
		return ;
	tmp = *b;
	while (tmp->next)
	{
		second_last = tmp;
		tmp = tmp->next;
	}
	second_last->next = NULL;
	tmp->prev = NULL;
	tmp->next = *b;
	(*b)->prev = tmp;
	*b = tmp;
	ft_putstr_fd("rrr\n", 1);
}