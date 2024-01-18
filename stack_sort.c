/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:34:02 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/18 03:05:31 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_max_at_top(t_stack **a, t_stack **b, int b_size)
{
	int		max;
	t_stack	*tmp;

	max = ft_find_max(*b);
	tmp = *b;
	while (tmp)
	{
		if (tmp->data == max)
		{
			if (tmp->index > b_size / 2)
			{
				while ((*b)->data != max)
					rrb(a, b);
				break ;
			}
			else
			{
				while ((*b)->data != max)
					rb(a, b);
				break ;
			}
		}
		tmp = tmp->next;
	}
}

void	update_index(t_stack **b)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *b;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

void	move_to_b(t_stack **a, t_stack **b, t_sorted *sorted)
{
	if ((*a)->data < sorted->sorted_array[sorted->start])
	{
		pb(a, b);
		rb(a, b);
		(sorted->start)++;
		(sorted->end)++;
	}
	else if ((*a)->data >= sorted->sorted_array[sorted->start]
		&& (*a)->data <= sorted->sorted_array[sorted->end])
	{
		pb(a, b);
		if ((*b)->next && (*b)->data < (*b)->next->data)
			sb(a, b);
		(sorted->start)++;
		(sorted->end)++;
	}
	else
		ra(a, b);
}

void	sort(t_stack **a, t_stack **b, int size)
{
	int			chunk_size;
	t_sorted	sorted;

	chunk_size = get_chunk_size(size);
	sorted.sorted_array = stack_to_array(*a, size);
	sorted.start = 0;
	sorted.end = chunk_size - 1;
	while ((*a))
	{
		if (sorted.end >= size)
			(sorted.end)--;
		if (sorted.start >= sorted.end)
			(sorted.start)--;
		move_to_b(a, b, &sorted);
	}
	free(sorted.sorted_array);
	while ((*b))
	{
		update_index(b);
		make_max_at_top(a, b, ft_stack_size(*b));
		pa(a, b);
	}
}
