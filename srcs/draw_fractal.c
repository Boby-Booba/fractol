/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ennollet <ennollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:34:08 by ennollet          #+#    #+#             */
/*   Updated: 2023/02/09 16:43:06 by ennollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	choose_fractal(double re, double im, int max_iter, t_vars *data)
{
	if (data->nb_fractal == 1)
		return (test_mandelbrot(re, im, max_iter));
	if (data->nb_fractal == 2)
		return (test_julia(re, im, max_iter, data));
	if (data->nb_fractal == 3)
		return (test_burning_ship(re, im, max_iter));
	return (0);
}

int	draw_fractal(t_vars *mlx, int x)
{
	int			y;
	double		zoom_x;
	double		zoom_y;
	t_complex	z;
	double		i;

	zoom_x = WIDTH / (mlx->max.re - mlx->min.re);
	zoom_y = HEIGHT / (mlx->max.im - mlx->min.im);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			z = init_cmpx(x / zoom_x + mlx->min.re, y / zoom_y + mlx->min.im);
			i = choose_fractal(z.re, z.im, mlx->max_iter, mlx);
			my_mlx_pixel_put(&mlx->img, x, y, (i / 100) * 0xFF + \
			((i / 100) * 0xFF00) + ((i / 100) * 0xFF0000) * 18 * mlx->shift);
			if (i == mlx->max_iter)
				my_mlx_pixel_put(&mlx->img, x, y, 0x00);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.mlx_img, 0, 0);
	return (0);
}

int	error_message(void)
{
	ft_putstr_fd("Wrong arguments !\nChoose the name of the fractal in", 2);
	ft_putstr_fd(" first argument :\n'", 2);
	ft_putstr_fd("mandelbrot', julia, or 'burning_ship'\n", 2);
	ft_putstr_fd("If you choose julia give two number between", 2);
	ft_putstr_fd(" -2 and 2 for the second and third argument\n", 2);
	ft_putstr_fd("If you choose an another fractal just give the name", 2);
	ft_putstr_fd(" of the fractal", 2);
	return (0);
}
