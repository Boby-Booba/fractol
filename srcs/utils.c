/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ennollet <ennollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:21:42 by ennollet          #+#    #+#             */
/*   Updated: 2023/02/09 16:43:39 by ennollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	return (res * sign);
}

double	atod(char *str)
{
	int		nb_zero;
	double	ent;
	double	deci;
	char	*deci_tmp;

	nb_zero = 0;
	ent = ft_atoi(str);
	deci_tmp = ft_strchr(str, '.');
	if (!deci_tmp)
		return (ent);
	deci_tmp++;
	while (*deci_tmp++ == '0')
		nb_zero++;
	deci_tmp -= nb_zero + 1;
	deci = ft_atoi(deci_tmp);
	while (deci >= 1)
		deci /= 10.0;
	while (nb_zero-- != 0)
		deci /= 10.0;
	if (str[0] == '-')
		return (ent - deci);
	return (ent + deci);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	tmp;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		tmp = write(fd, &s[i], 1);
		i++;
	}
	(void)tmp;
}
