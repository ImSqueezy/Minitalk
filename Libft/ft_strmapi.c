/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <aouaalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:07:30 by aouaalla          #+#    #+#             */
/*   Updated: 2024/11/07 02:15:01 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*p;
	size_t		i;

	if (!s || !f)
		return (NULL);
	p = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		*(p + i) = f(i, *(s + i));
		i++;
	}
	p[i] = '\0';
	return (p);
}
