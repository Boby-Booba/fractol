/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ennollet <ennollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:57:26 by ennollet          #+#    #+#             */
/*   Updated: 2023/02/10 10:26:54 by ennollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_arg(char **av, t_vars *data, int ac)
{	
	data->nb_fractal = -1;
	if (ft_strcmp(av[1], "mandelbrot") == 0 && ac < 3)
		data->nb_fractal = 1;
	else if (ft_strcmp(av[1], "julia") == 0)
	{
		if (!av[2] || !av[3] || is_number(av) == 0 || is_valid_number(av) == 0)
			return (-1);
		data->julia = init_cmpx(atod(av[2]), atod(av[3]));
		if (fabs(data->julia.re) > 2 || fabs(data->julia.im) > 2)
			return (-1);
		data->nb_fractal = 2;
	}
	else if (ft_strcmp(av[1], "burning_ship") == 0 && ac < 3)
		data->nb_fractal = 3;
	if (data->nb_fractal == -1)
		return (-1);
	return (0);
}

int	init_mlx(t_vars *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (0);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract'ol");
	if (data->win == NULL)
	{
		free(data->win);
		return (0);
	}
	data->img.mlx_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	init_iter_zoom(data);
	init_struct(data);
	return (0);
}

int	ft_exit(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.mlx_img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int	main(int ac, char **av)
{
	t_vars	data;

	if (ac < 2 || ac > 4 || check_arg(av, &data, ac) == -1)
		return (error_message());
	init_mlx(&data);
	draw_fractal(&data, 0);
	mlx_hook(data.win, ButtonPress, ButtonPressMask, &zoom, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &ft_keypress, &data);
	mlx_hook(data.win, 17, 0, &ft_exit, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img.mlx_img);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}
