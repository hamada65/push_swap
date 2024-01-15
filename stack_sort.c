/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:34:02 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/15 20:09:03 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int stack_size)
{
	
	if (stack_size >= 6 && stack_size <= 16)
		return (3);
	else if (stack_size <= 100)
		return (13);
	else if (stack_size <= 500)
		return (35);
	return (45);
}


void	sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				tmp = tab[j];
				tab[j] = tab[i];
				tab[i] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*stack_to_array(t_stack *a, int size)
{
	int		*sorted_array;
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	sorted_array = malloc(sizeof(int) * size);
	while (tmp)
	{
		sorted_array[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	sort_int_tab(sorted_array, size);
	return (sorted_array);
}

int	ft_stack_last(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->data);
}

int	ft_find_max(t_stack *stack)
{
	int	max;

	max = stack->data;
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

void	make_max_at_top(t_stack **a, t_stack **b, int b_size)
{
	int	max;
	t_stack *tmp;

	max = ft_find_max(*b);
	tmp = *b;
	while (tmp)
	{
		if (tmp->data == max)
		{
			if (tmp->index > b_size/2)
			{
				while ((*b)->data != max)
					rrb(a, b);
			}
			else
			{
				while ((*b)->data != max)
					rb(a, b);
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

void	sort(t_stack **a, t_stack **b, int size)
{
	int	chunk_size;
	int	*sorted_array;
	int	start;
	int	end;

	chunk_size = get_chunk_size(size);
	sorted_array = stack_to_array(*a, size);
	start = 0;
	end = chunk_size - 1;
	while ((*a))
	{
		if (start >= end)
			start--;
		if (end >= size)
			end--;
		if ((*a)->data <= sorted_array[start])
		{
			pb(a, b);
			rb(a, b);
			start++;
			end++;
		}
		else if ((*a)->data > sorted_array[start] && (*a)->data <= sorted_array[end])
		{
			pb(a, b);
			if ((*b)->next && (*b)->data < (*b)->next->data)
				rb(a, b);
			start++;
			end++;
		}
		else
			ra(a, b);	
	}
	while ((*b))
	{
		update_index(b);
		make_max_at_top(a, b, ft_stack_size(*b));
		pa(a, b);
	}
	free(sorted_array);
}