/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:21:31 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/15 23:41:34 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

t_stack	*ft_nb_new(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = nb;
	new->next = NULL;
	new->prev = NULL;
	return (new);
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

void	ft_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;
	t_stack	*prev;

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

static int	ft_atoi_check_llong(long long result, char *str, int sign)
{
	if ((result > 922337203685477580) || (result == 922337203685477580 && (*str
				- '0') > 7))
	{
		if (sign == 1)
			return (-1);
		else if (sign == -1)
			return (0);
	}
	return (2);
}

int	is_int(char *str)
{
	int sign;
	long long result;

	result = 0;
	sign = 1;
	if (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		if (ft_atoi_check_llong(result, str, sign) != 2)
			return (0);
		result = result * 10 + (*str - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			return (0);
		str++;
	}
	return (1);
}
