/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <aouaalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:41:18 by aouaalla          #+#    #+#             */
/*   Updated: 2024/11/11 21:11:37 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	n;

	n = count * size;
	if (n == 0)
		return (malloc(0));
	if (count && count != n / size)
		return (0);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, n);
	return (p);
}
