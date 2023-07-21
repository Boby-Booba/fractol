/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ennollet <ennollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:58:30 by ennollet          #+#    #+#             */
/*   Updated: 2023/02/10 11:17:58 by ennollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	operation(double start, double end, double zoom)
{
	return (start + ((end - start) * zoom));
}

int	zoom(int key, int x, int y, t_vars *mlx)
{
	double		zoom;
	t_complex	mouse;

	mouse.re = (mlx->min.re + x * ((mlx->max.re - mlx->min.re) / (WIDTH)));
	mouse.im = (mlx->min.im + y * ((mlx->max.im - mlx->min.im) / (HEIGHT)));
	if (key == 4)
	{
		zoom = 0.80;
		if (mlx->max_iter < 100)
			mlx->max_iter += 2;
	}
	else if (key == 5)
	{
		zoom = 1.20;
		if (mlx->max_iter > 20)
			mlx->max_iter -= 2;
	}
	else
		zoom = 1;
	mlx->min.re = operation(mouse.re, mlx->min.re, zoom);
	mlx->max.re = operation(mouse.re, mlx->max.re, zoom);
	mlx->min.im = operation(mouse.im, mlx->min.im, zoom);
	mlx->max.im = operation(mouse.im, mlx->max.im, zoom);
	draw_fractal(mlx, 0);
	return (0);
}

void	direction(int keycode, t_vars *vars)
{
	double	intervalle_re;
	double	intervalle_im;

	intervalle_re = vars->max.re - vars->min.re;
	intervalle_im = vars->max.im - vars->min.im;
	if (keycode == LEFT)
	{
		vars->min.re -= (intervalle_re * 0.05);
		vars->max.re -= (intervalle_re * 0.05);
	}
	if (keycode == RIGHT)
	{
		vars->min.re += (intervalle_re * 0.05);
		vars->max.re += (intervalle_re * 0.05);
	}
	if (keycode == UP)
	{
		vars->min.im -= (intervalle_im * 0.05);
		vars->max.im -= (intervalle_im * 0.05);
	}
	if (keycode == DOWN)
	{
		vars->min.im += (intervalle_im * 0.05);
		vars->max.im += (intervalle_im * 0.05);
	}
}

int	ft_keypress(int keycode, t_vars *vars)
{		
	if (keycode == 65307)
		ft_exit(vars);
	direction(keycode, vars);
	if (keycode == PLUS)
		vars->max_iter += 5;
	if (keycode == MINUS)
		vars->max_iter -= 5;
	if (keycode == 99)
	{
		if (vars->shift == 1)
			vars->shift = 1.11111111;
		else
			vars->shift = 1;
	}
	draw_fractal(vars, 0);
	return (0);
}
