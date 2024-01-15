/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:50:27 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/15 18:00:09 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int		size;

	stack_b = NULL;
	if (ac >= 2)
	{
		stack_a = check_args(ac, av);
		if (is_stack_sorted(stack_a) == 1)
		{
			ft_clear_stack(&stack_a);
			return (0);
		}
		size = ft_stack_size(stack_a);
		// printf("size = %d\n", size);
		if (size == 2)
			sa(&stack_a, &stack_b);
		if (size == 3)
			sort_three(&stack_a, &stack_b);
		else if (size == 4)
			sort_four(&stack_a, &stack_b);
		else if (size == 5)
			sort_five(&stack_a, &stack_b);
		else
			sort(&stack_a, &stack_b, size);
		// printf("Stack A:\n");
		// ft_print_list(stack_a);
		// printf("Stack B:\n");
		// ft_print_list(stack_b);
		ft_clear_stack(&stack_a);
		ft_clear_stack(&stack_b);
	}
	else
	{
		// ft_putstr_fd("Error\nMissing Args\n", 2);
	}
	return (0);
}
