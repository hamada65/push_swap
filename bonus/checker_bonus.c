/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:06:09 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/16 20:50:00 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_start_reading(t_stack **a, t_stack **b)
{
	char *str;
	char *tmp; 

	str = get_next_line(0);
	tmp = ft_strtrim(str, "\n");
	free(str);
	str = tmp;
	while (str)
	{
		if (ft_strncmp(str, "sa", 3) == 0)
			sa(a, b);
		else if (ft_strncmp(str, "sb", 3) == 0)
			sb(a, b);
		else if (ft_strncmp(str, "ss", 3) == 0)
			ss(a, b);
		else if (ft_strncmp(str, "pa", 3) == 0)
			pa(a, b);
		else if (ft_strncmp(str, "pb", 3) == 0)
			pb(a, b);
		else if (ft_strncmp(str, "ra", 3) == 0)
			ra(a, b);
		else if (ft_strncmp(str, "rb", 3) == 0)
			rb(a, b);
		else if (ft_strncmp(str, "rr", 3) == 0)
			rr(a, b);
		else if (ft_strncmp(str, "rra", 4) == 0)
			rra(a, b);
		else if (ft_strncmp(str, "rrb", 4) == 0)
			rrb(a, b);
		else if (ft_strncmp(str, "rrr", 4) == 0)
			rrr(a, b);
		else
		{
			free(str);
			ft_putstr_fd("KO\n", 2);
			ft_clear_stack(a);
			ft_clear_stack(b);
			exit(1);
		}
		free(str);
		str = get_next_line(0);
		if (str)
		{
			tmp = ft_strtrim(str, "\n");
			free(str);
			str = tmp;
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	stack_b = NULL;
	if (ac >= 2)
	{
		stack_a = check_args(ac, av);
		ft_start_reading(&stack_a, &stack_b);
		if (is_stack_sorted(stack_a) == 1 && ft_stack_size(stack_b) == 0)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 2);
		ft_clear_stack(&stack_a);
		ft_clear_stack(&stack_b);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
	}
}