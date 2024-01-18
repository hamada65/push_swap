/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_short.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:19:23 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/18 02:59:17 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, t_stack **b)
{
	if (is_stack_sorted(*a) == 1)
		return ;
	if ((*a)->data > (*a)->next->data && (*a)->data < (*a)->next->next->data)
		sa(a, b);
	else if ((*a)->data > (*a)->next->data
		&& (*a)->data > (*a)->next->next->data)
	{
		if ((*a)->next->data < (*a)->next->next->data)
			ra(a, b);
		else
		{
			ra(a, b);
			sa(a, b);
		}
	}
	else if ((*a)->data < (*a)->next->data
		&& (*a)->data > (*a)->next->next->data)
		rra(a, b);
	else if ((*a)->data < (*a)->next->data
		&& (*a)->data < (*a)->next->next->data)
	{
		ra(a, b);
		sa(a, b);
		rra(a, b);
	}
}

int	ft_find_min(t_stack *stack, int *min2)
{
	int	min;

	if (min2 && *min2 && *min2 == stack->data)
		stack = stack->next;
	min = stack->data;
	while (stack)
	{
		if (stack->data < min && (!min2 || stack->data != *min2))
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

void	sort_three_and_pa(t_stack **a, t_stack **b)
{
	sort_three(a, b);
	pa(a, b);
	pa(a, b);
	if ((*a)->data > (*a)->next->data)
		sa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int		min;
	int		min2;
	int		found_both;

	min = ft_find_min(*a, NULL);
	min2 = ft_find_min(*a, &min);
	found_both = 0;
	while (found_both < 2)
	{
		if ((*a)->data == min)
		{
			pb(a, b);
			found_both++;
		}
		else if ((*a)->data == min2)
		{
			pb(a, b);
			found_both++;
		}
		else
			ra(a, b);
	}
	sort_three_and_pa(a, b);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int		min;

	min = ft_find_min(*a, NULL);
	while ((*a)->data != min)
		ra(a, b);
	pb(a, b);
	sort_three(a, b);
	pa(a, b);
}
