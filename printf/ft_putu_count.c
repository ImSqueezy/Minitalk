/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:54:26 by aouaalla          #+#    #+#             */
/*   Updated: 2024/11/20 17:31:11 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putu_count(int *i, unsigned int u)
{
	char	a;

	if (u <= 9)
	{
		a = u + 48;
		ft_putchar_count(i, a);
	}
	else
	{
		ft_putu_count(i, u / 10);
		ft_putu_count(i, u % 10);
	}
}
