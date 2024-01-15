/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_cheker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:57:39 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/15 23:25:47 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_digits(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ' && av[i][j] != '+' && av[i][j] != '-'
				&& ft_isdigit(av[i][j]) == 0)
			{
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	free_2d_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	check_duplicates(t_stack *stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack_a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->data == tmp2->data)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	arg_check(char *str, t_stack **a)
{
	int	j;
	char	**tmp;

	if (ft_strlen(str) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_clear_stack(a);
		exit(1);
	}
	tmp = ft_split(str, ' ');
	j = 0;
	while (tmp[j])
	{
		if (is_int(tmp[j]) == 0 || ft_strncmp(tmp[j], "+", 2) == 0
			|| ft_strncmp(tmp[j], "-", 2) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			free_2d_array(tmp);
			ft_clear_stack(a);
			exit(1);
		}
		ft_add_back(a, ft_nb_new(ft_atoi(tmp[j])));
		j++;
	}
	free_2d_array(tmp);
}

t_stack	*check_args(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;

	stack_a = NULL;
	if (check_digits(ac, av))
	{
		i = 1;
		while (i < ac)
		{
			arg_check(av[i], &stack_a);
			i++;
		}
	}
	if (check_duplicates(stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		ft_clear_stack(&stack_a);
		exit(1);
	}
	return (stack_a);
}
