/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:02:01 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/15 23:32:09 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

	if (ft_stack_size(*a) < 2)
		return ;
	tmp = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	tmp->prev = *a;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	printf("sa\n");
}

// (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (ft_stack_size(*b) < 2)
		return ;
	tmp = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	tmp->prev = *b;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	printf("sb\n");
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
	printf("ss\n");
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
	printf("pa\n");
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
	printf("pb\n");
}

// (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.

void	ra(t_stack **a, t_stack **b)
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
	printf("ra\n");
}

// (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.

void	rb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (ft_stack_size(*b) < 2)
		return ;
	tmp = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	tmp->prev = NULL;
	tmp->next = NULL;
	ft_add_back(b, tmp);
	printf("rb\n");
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
	printf("rr\n");
}

// (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*second_last;

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
	printf("rra\n");
}

// (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*second_last;

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
	printf("rrb\n");
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
	printf("rrr\n");
}