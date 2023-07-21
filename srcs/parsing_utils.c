/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ennollet <ennollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:55:11 by ennollet          #+#    #+#             */
/*   Updated: 2023/02/10 11:32:55 by ennollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_moposoc(int c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '.')
		return (1);
	return (0);
}

int	is_number(char **av)
{
	int	i;
	int	j;

	i = 2;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && !ft_is_moposoc(av[i][j]))
				return (0);
		j++;
		}
	i++;
	}
	return (1);
}

int	is_valid_number(char **av)
{
	int	i;
	int	j;

	i = 2;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+' || av[i][j] == '-')
			{
				if (av[i][j + 1] && !ft_isdigit(av[i][j + 1]))
					return (0);
			}
			if (av[i][j] == '.')
			{
				if ((av[i][j + 1] && !ft_isdigit(av[i][j + 1])) || \
				(av[i][j - 1] && !ft_isdigit(av[i][j - 1])))
					return (0);
			}
		j++;
		}
	i++;
	}
	return (1);
}
