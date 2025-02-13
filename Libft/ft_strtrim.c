/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <aouaalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:05:42 by aouaalla          #+#    #+#             */
/*   Updated: 2024/11/09 00:00:30 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkset(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		j;
	int		len;

	if (!set && !s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	else if (!s1)
		return (0);
	if (!ft_strlen(s1))
		return (ft_strdup(""));
	while (checkset(set, *s1))
		s1++;
	j = ft_strlen(s1) - 1;
	while (checkset(set, s1[j]))
		j--;
	len = j + 1;
	p = ft_substr(s1, 0, len);
	return (p);
}
