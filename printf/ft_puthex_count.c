/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:53:10 by aouaalla          #+#    #+#             */
/*   Updated: 2024/11/20 17:30:31 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putuhex_count(int *i, unsigned int u)
{
	char	*uhex_order;

	uhex_order = "0123456789ABCDEF";
	if (u < 16)
		ft_putchar_count(i, uhex_order[u]);
	else
	{
		ft_putuhex_count(i, u / 16);
		ft_putuhex_count(i, u % 16);
	}
}

static void	ft_putlhex_count(int *i, unsigned int u)
{
	char	*lhex_order;

	lhex_order = "0123456789abcdef";
	if (u < 16)
		ft_putchar_count(i, lhex_order[u]);
	else
	{
		ft_putlhex_count(i, u / 16);
		ft_putlhex_count(i, u % 16);
	}
}

void	ft_puthex_count(int *i, char c, unsigned int u)
{
	if (c == 'x')
		ft_putlhex_count(i, u);
	else if (c == 'X')
		ft_putuhex_count(i, u);
}
