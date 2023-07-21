/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ennollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:17:26 by ennollet          #+#    #+#             */
/*   Updated: 2022/11/14 18:04:33 by ennollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *str, char s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == s)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != s)
			i++;
	}
	return (count);
}

static int	ft_word_len(char const *str, char s)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != s)
		i++;
	return (i);
}

static char	*ft_malloc_word(char const *str, char s)
{
	int		i;
	int		wl;
	char	*tab;

	i = 0;
	wl = ft_word_len(str, s);
	tab = (char *)malloc(sizeof(char) * (wl + 1));
	if (!tab)
		return (NULL);
	while (i < wl)
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = 0;
	return (tab);
}

static void	*ft_free_all(char **strs, int i)
{
	while (i >= 0)
	{
		free(strs[i]);
		i--;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;

	if (!s)
		return (0);
	i = 0;
	tab = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			tab[i] = ft_malloc_word(s, c);
			if (tab[i] == NULL)
				return (ft_free_all(tab, i - 1));
			i++;
		}
		while (*s != '\0' && *s != c)
			s++;
	}
	tab[i] = 0;
	return (tab);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	int	i;
	char **split;
	(void)ac;
	split = ft_split(av[1], av[2][0]);
	i = 0;
	while (split[i])
	{
		printf("%s\n", (split[i]));
		i++;

	}
}*/
