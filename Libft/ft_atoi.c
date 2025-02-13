/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <aouaalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:08:07 by aouaalla          #+#    #+#             */
/*   Updated: 2024/11/10 10:38:55 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_wspace(int i)
{
	return (i == 32 || (i >= 9 && i <= 13));
}

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (is_wspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9')
	{
		if (num > (LLONG_MAX - (*str - '0')) / 10)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		num = num * 10 + (*str - '0');
		str++;
	}
	return (((int )num) * sign);
}
