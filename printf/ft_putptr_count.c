/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:55:07 by aouaalla          #+#    #+#             */
/*   Updated: 2024/11/20 17:30:51 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_count(int *i, void *p)
{
	unsigned long	address;
	char			*hex_order;

	hex_order = "0123456789abcdef";
	address = (unsigned long)p;
	if (!address)
	{
		ft_putchar_count(i, '0');
		return ;
	}
	if (address >= 16)
	{
		ft_putptr_count(i, (void *)(address / 16));
		ft_putchar_count(i, hex_order[address % 16]);
	}
	else
		ft_putchar_count(i, hex_order[address]);
}
