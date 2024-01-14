/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:34:02 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/14 18:44:06 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int stack_size)
{
	int chunk_size;

	chunk_size = stack_size / 4;
	if (stack_size % 4 != 0)
		chunk_size++;
	return (chunk_size);
}

void	make_chunks(t_stack *a, t_stack *b, int chunk_size, int *sorted_array)
{
	// t_stack *tmp;

	// tmp = a;
	// while (tmp)
	// {
	// 	if (tmp->chunk)
	// 		tmp->chunk = 0;
	// 	tmp = tmp->next;
	// }
	// tmp = a;
	// while (chunk_size > 0)
	// {
	// 	tmp->chunk = 1;
	// 	tmp = tmp->next;
	// 	chunk_size--;
	// }
}

void	print_chunks(t_stack *a)
{
	t_stack *tmp;

	tmp = a;
	while (tmp && tmp->chunk)
	{
		printf("data: %d, chunk: %d\n", tmp->data, tmp->chunk);
		tmp = tmp->next;
	}
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

void	move_chunks(t_stack **a, int chunk_size)
{
	t_stack *tmp;

	tmp = *a;
	while (tmp->under_chunk)
		tmp = tmp->next;
	tmp->under_chunk = 1;
	tmp->chunk = 0;
	while (chunk_size > 0)
	{
		if (!tmp->next)
			return ;
		tmp = tmp->next;
	}
	tmp->chunk = 1;
}

void	sort(t_stack **a, t_stack **b, int size)
{
	int chunk_size;
	int *sorted_array;

	chunk_size = get_chunk_size(size);
	// printf("chunk_size: %d\n", chunk_size);
	// print_chunks(*a);
	sorted_array = stack_to_array(*a, size);
	make_chunks(*a, *b, chunk_size, sorted_array);
	while (!(is_stack_sorted(*a)))
	{
		if ((*a)->chunk)
		{
			move_chunks(a, chunk_size);
			pb(a, b);
			if ((*b)->next && (*b)->data < (*b)->next->data)
				rb(a, b);
		}
		else if ((*a)->under_chunk)
		{
			move_chunks(a, chunk_size);
			pb(a, b);
			rb(a, b);
		}
		else
			ra(a, b);
		// printf("Stack A:\n");
		// ft_print_list(*a);
		// printf("Stack B:\n");
		// ft_print_list(*b);
		// printf("------------------\n");
	}
	free(sorted_array);
}