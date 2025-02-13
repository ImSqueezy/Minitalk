/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <aouaalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:32:43 by aouaalla          #+#    #+#             */
/*   Updated: 2024/11/09 22:31:33 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*p;
	size_t		size;

	size = ft_strlen(s1) + 1;
	p = (char *)malloc(size * sizeof(char));
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s1, size);
	return (p);
}
