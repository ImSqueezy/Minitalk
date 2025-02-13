/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <aouaalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:05:25 by aouaalla          #+#    #+#             */
/*   Updated: 2024/11/09 19:11:31 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c, size_t len)
{
	size_t	i;
	int		count;
	char	last_c;

	count = 0;
	i = 0;
	last_c = s[i];
	if (!last_c)
		return (0);
	while (i <= len)
	{
		if ((s[i] == c || s[i] == '\0') && last_c != c)
			count++;
		last_c = s[i];
		i++;
	}
	return (count);
}

static char	*initilazing(char const *s, char c)
{
	char	*p;
	int		i;
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	i = 0;
	while (i < len)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static void	ft_free(char **p)
{
	while (*p)
	{
		free(*p);
		p++;
	}
	free(p);
}

char	**ft_split(char const *s, char c)
{
	size_t		words;
	size_t		i;
	char		**p;

	if (!s)
		return (0);
	words = count_words(s, c, ft_strlen(s));
	p = (char **)malloc((words + 1) * sizeof(char *));
	if (p == NULL)
		return (0);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		p[i] = initilazing(s, c);
		if (p[i] == NULL)
			return (ft_free(p), NULL);
		s += ft_strlen(p[i]);
		i++;
	}
	p[i] = NULL;
	return (p);
}
