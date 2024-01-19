/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:30:56 by mel-rhay          #+#    #+#             */
/*   Updated: 2024/01/19 20:00:07 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

long long	ft_atoi(const char *nptr)
{
	char		*str;
	int			sign;
	long long	result;

	str = (char *)nptr;
	result = 0;
	sign = 1;
	while (*str && (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
			|| *str == '\t' || *str == '\v'))
		str++;
	if (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		if (ft_atoi_check_llong(result, str, sign) != 2)
			return (ft_atoi_check_llong(result, str, sign));
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((result * sign));
}
