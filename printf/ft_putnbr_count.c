/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:53:47 by aouaalla          #+#    #+#             */
/*   Updated: 2024/11/20 17:30:40 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_count(int	*i, int nbr)
{
	char		a;
	long long	num;

	num = nbr;
	if (num < 0)
	{
		ft_putchar_count(i, '-');
		num *= -1;
	}
	if (num >= 0 && num <= 9)
	{
		a = num + 48;
		ft_putchar_count(i, a);
	}
	else
	{
		ft_putnbr_count(i, num / 10);
		ft_putnbr_count(i, num % 10);
	}
}
