/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ennollet <ennollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:12:00 by ennollet          #+#    #+#             */
/*   Updated: 2023/02/10 11:20:45 by ennollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# include <X11/X.h>
# include <unistd.h>

# define HEIGHT 480
# define WIDTH 720
# define LEFT	65361
# define RIGHT  65363
# define UP	  65362
# define DOWN  65364
# define  PLUS 65451
# define MINUS 65453

typedef struct s_complex
{
	double	re;
	double	im;	
}	t_complex;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_complex	min;
	t_complex	max;
	t_complex	c;
	t_complex	julia;
	double		zoom;
	int			max_iter;
	int			nb_fractal;
	double		shift;
}			t_vars;

void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
t_complex	init_cmpx(double re, double im);
void		init_iter_zoom(t_vars *mlx);
void		init_struct(t_vars *mlx);
int			test_mandelbrot(double x, double y, int max_iter);
int			test_julia(double x, double y, int max_iter, t_vars *data);
int			test_burning_ship(double x, double y, int max_iter);
double		operation(double start, double end, double zoom);
int			zoom(int key, int x, int y, t_vars *mlx);
int			ft_keypress(int keycode, t_vars *vars);
double		atod(char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			draw_fractal(t_vars *mlx, int x);
int			ft_exit(t_vars *vars);
void		ft_putstr_fd(char *str, int fd);
int			error_message(void);
int			is_valid_number(char **av);
int			is_number(char **av);

#endif