/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <aouaalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:33:45 by aouaalla          #+#    #+#             */
/*   Updated: 2024/11/09 19:12:06 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_sign(int n)
{
	if (n < 0)
		return (0);
	return (1);
}

static int	digit_counter(int n)
{
	int	count;

	count = 0;
	if (!number_sign(n))
		count++;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	itoa_converting(char *p, int n, int digits)
{
	int	j;

	p[digits] = '\0';
	if (!number_sign(n))
	{
		n *= -1;
		p[0] = '-';
		j = digits - 1;
		while (j > 0)
		{
			p[j] = (n % 10) + 48;
			n = n / 10;
			j--;
		}
	}
	else
	{
		j = digits - 1;
		while (j >= 0)
		{
			p[j] = (n % 10) + 48;
			n = n / 10;
			j--;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*p;

	if (!n)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	p = (char *)malloc((digit_counter(n) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	itoa_converting(p, n, digit_counter(n));
	return (p);
}
