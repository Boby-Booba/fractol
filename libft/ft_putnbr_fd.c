/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ennollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:03:41 by ennollet          #+#    #+#             */
/*   Updated: 2022/11/11 15:22:25 by ennollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	x;

	if (n < 0)
	{
		x = -n;
		ft_putchar_fd('-', fd);
	}	
	else
		x = n;
	if (x > 9)
	{
		ft_putnbr_fd(x / 10, fd);
		x = x % 10;
	}
	ft_putchar_fd(x + '0', fd);
}
