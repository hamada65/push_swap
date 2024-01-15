/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:46:47 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/15 21:47:39 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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