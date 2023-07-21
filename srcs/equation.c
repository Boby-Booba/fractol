/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ennollet <ennollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:48:27 by ennollet          #+#    #+#             */
/*   Updated: 2023/02/09 14:28:55 by ennollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	test_mandelbrot(double x, double y, int max_iter)
{
	double	z_r;
	double	z_i;
	double	i;
	double	tmp;

	z_r = 0;
	z_i = 0;
	i = 0;
	while ((z_r * z_r + z_i * z_i) < 4 && i < max_iter)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + x;
		z_i = 2 * z_i * tmp + y;
		i++;
	}
	return (i);
}

int	test_julia(double x, double y, int max_iter, t_vars *data)
{
	double	z_r;
	double	z_i;
	double	i;
	double	tmp;

	z_r = y;
	z_i = x;
	i = 0;
	while ((z_r * z_r + z_i * z_i) < 4 && i < max_iter)
	{
		tmp = z_r * z_r - z_i * z_i + data->julia.re;
		z_i = 2 * z_i * z_r + data->julia.im;
		z_r = tmp;
		i++;
	}
	return (i);
}

int	test_burning_ship(double x, double y, int max_iter)
{
	double	z_r;
	double	z_i;
	double	i;
	double	tmp;

	z_r = 0;
	z_i = 0;
	i = 0;
	while ((z_r * z_r + z_i * z_i) < 4 && i < max_iter)
	{
		tmp = z_r;
		z_r = fabs(z_r * z_r - z_i * z_i + x);
		z_i = fabs(2 * z_i * tmp + y);
		i++;
	}
	return (i);
}
