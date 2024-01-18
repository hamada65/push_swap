/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 02:32:28 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/18 02:33:08 by mel-rhay         ###   ########.fr       */
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
	int	i;
	int	j;
	int	tmp;

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
