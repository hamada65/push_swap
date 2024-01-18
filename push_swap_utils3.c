/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:46:47 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/18 02:21:17 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	ft_putstr_fd("pb\n", 1);
}

// (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	(void)b;
	if (ft_stack_size(*a) < 2)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_add_back(a, tmp);
	ft_putstr_fd("ra\n", 1);
}

t_stack	*ft_nb_new(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = nb;
	new->next = NULL;
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

	if (!(*lst))
		*lst = new;
	else
	{
		tmp = (*lst);
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
