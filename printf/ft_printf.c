/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:51:19 by aouaalla          #+#    #+#             */
/*   Updated: 2025/02/13 10:31:46 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	specifier_handler(int *count, char c, va_list p2)
{
	if (c == 's')
		ft_putstr_count(count, va_arg(p2, char *));
	else if (c == 'c')
		ft_putchar_count(count, va_arg(p2, int));
	else if (c == '%')
		ft_putchar_count(count, c);
	else if (c == 'd' || c == 'i')
		ft_putnbr_count(count, va_arg(p2, int));
	else if (c == 'u')
		ft_putu_count(count, va_arg(p2, unsigned int));
	else if (c == 'x' || c == 'X')
		ft_puthex_count(count, c, va_arg(p2, unsigned int));
	else if (c == 'p')
	{
		ft_putchar_count(count, '0');
		ft_putchar_count(count, 'x');
		ft_putptr_count(count, va_arg(p2, void *));
	}
	else
		ft_putchar_count(count, c);
}

static int	count_elements(const char *ptr, va_list p)
{
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] != '%')
		{
			write(1, &ptr[i], 1);
			count++;
		}
		else
		{
			i++;
			if (ptr[i])
				specifier_handler(&count, ptr[i], p);
			if (ptr[i] == '\0')
				break ;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	p;
	int		count;

	va_start(p, str);
	count = count_elements(str, p);
	va_end(p);
	return (count);
}
