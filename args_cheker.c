/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_cheker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:57:39 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/13 22:59:58 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (av[i][j] != ' ' && av[i][j] != '+' && av[i][j] != '-' && ft_isdigit(av[i][j]) == 0)
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

void	ft_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;
	t_stack *prev;

	if (!(*lst))
		*lst = new;
	else
	{
		tmp = (*lst);
		while (tmp && tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		tmp->next = new;
		new->prev = prev;
	}
}

t_stack	*ft_nb_new(int nb)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = nb;
	new->next = NULL;
	new->prev = NULL;
	new->chunk = 0;
	return (new);
}

void ft_print_list(t_stack *lst)
{
	t_stack *tmp;

	tmp = lst;
	while (tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

void	ft_clear_stack(t_stack **lst)
{
	t_stack	*tmp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

t_stack	*check_args(int ac, char **av)
{
	t_stack	*stack_a;
	char	**tmp;
	int		i;
	int 	j;

	stack_a = NULL;
	if (check_digits(ac, av))
	{
		i = 1;
		while (i < ac)
		{
			if (ft_strlen(av[i]) == 0)
			{
				ft_putstr_fd("Error\nEmpty String\n", 2);
				ft_clear_stack(&stack_a);
				exit(1);
			}
			tmp = ft_split(av[i], ' ');
			j = 0;
			while (tmp[j])
			{
				if (is_int(tmp[j]) == 0)
				{
					ft_putstr_fd("Error\nNot Integers\n", 2);
					free_2d_array(tmp);
					ft_clear_stack(&stack_a);
					exit(1);
				}
				ft_add_back(&stack_a, ft_nb_new(ft_atoi(tmp[j])));
				j++;
			}
			free_2d_array(tmp);
			i++;
		}
	}
	if (check_duplicates(stack_a))
	{
		ft_putstr_fd("Error\nDuplicated Integer", 2);
		ft_clear_stack(&stack_a);
		exit(1);
	}
	// ft_print_list(stack_a);
	// ft_clear_stack(&stack_a);
	return (stack_a);
}