/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:28:04 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/13 17:36:41 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int is_int(char *str)
{
	int			sign;
	long long	result;

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