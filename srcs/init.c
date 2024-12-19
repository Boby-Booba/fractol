/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ennollet <ennollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:45:19 by ennollet          #+#    #+#             */
/*   Updated: 2024/12/19 13:56:04 by ennollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	init_cmpx(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void	init_iter_zoom(t_vars *mlx)
{
	mlx->max_iter = 40;
	mlx->zoom = 1;
	mlx->shift = 1;
}

void	init_struct(t_vars *mlx)
{
	if (mlx->nb_fractal == 1)
	{
		mlx->max = init_cmpx(0.6 * mlx->zoom, 1.2 * mlx->zoom);
		mlx->min = init_cmpx(-2.1 * mlx->zoom, -1.2 * mlx->zoom);
	}
	if (mlx->nb_fractal == 2)
	{
		mlx->max = init_cmpx(1.5 * mlx->zoom, 1.5 * mlx->zoom);
		mlx->min = init_cmpx(-1.5 * mlx->zoom, -1.5 * mlx->zoom);
	}
	if (mlx->nb_fractal == 3)
	{
		mlx->max = init_cmpx(-1.7 * mlx->zoom, 0.01 * mlx->zoom);
		mlx->min = init_cmpx(-1.8 * mlx->zoom, -0.08 * mlx->zoom);
	}
}
