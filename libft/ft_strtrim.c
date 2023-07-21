/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ennollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:33:24 by ennollet          #+#    #+#             */
/*   Updated: 2022/11/14 17:59:13 by ennollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isseparator(char c, char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s;
	size_t	e;
	size_t	i;
	char	*tab;

	if (!s1 || !set)
		return (0);
	s = 0;
	e = ft_strlen(s1);
	i = 0;
	while (isseparator(s1[s], set) && s1[s])
		s++;
	while (e > s && isseparator(s1[e - 1], set))
		e--;
	tab = (char *)malloc(sizeof(char) * (e - s + 1));
	if (!tab)
		return (NULL);
	while (s < e)
	{
		tab[i] = s1[s];
		i++;
		s++;
	}
	tab[i] = 0;
	return (tab);
}
