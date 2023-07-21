/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ennollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:13:37 by ennollet          #+#    #+#             */
/*   Updated: 2022/11/11 12:03:51 by ennollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static	int	ft_nb_len(int x)
{
	int	len;

	len = 0;
	if (x <= 0)
	{
		len++;
	}
	while (x != 0)
	{
		x = x / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*tab;

	len = ft_nb_len(n);
	tab = (char *)malloc(sizeof(char) * len + 1);
	if (!tab)
		return (NULL);
	tab[len] = '\0';
	if (n == 0)
		tab[0] = '0';
	if (n < 0)
		tab[0] = '-';
	len--;
	while (len >= 0 && n != 0)
	{
		tab[len] = ft_abs((n % 10)) + '0';
		n = n / 10;
		len--;
	}
	return (tab);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
	(void)ac;
        printf("%s\n", ft_itoa(atoi(av[1])));
}
*/
