
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:54:51 by aouaalla          #+#    #+#             */
/*   Updated: 2024/11/20 17:31:44 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar_count(int *i, char c);
void	ft_putstr_count(int	*i, char *s);
void	ft_putnbr_count(int	*i, int nbr);
void	ft_putu_count(int *i, unsigned int u);
void	ft_puthex_count(int *i, char c, unsigned int u);
void	ft_putptr_count(int *i, void *p);
int		ft_printf(const char *str, ...);

#endif
