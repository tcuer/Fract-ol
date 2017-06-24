/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 12:24:49 by tcuer             #+#    #+#             */
/*   Updated: 2017/06/24 18:37:01 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# define HEIGHT 800
# define WIDTH 800
# define X_MIN -2.0
# define X_MAX 2.0
# define Y_MIN -2.0
# define Y_MAX 2.0
# define ZOOM 1.1

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	int		r;
	int		g;
	int		bl;
	int		i_max;
	int		x;
	int		y;
	double	z_r;
	double	z_i;
	double	zoom;
	double	h;
	double	x2;
	double	y2;
	double	a;
	double	b;
	double	arrow_x;
	double	arrow_y;
	double	xz;
	double	yz;
	int		param;
	double	xmin;
	double	ymin;
	double	xmax;
	double	ymax;
	double	decalx;
	double	decaly;
	double	sx;
	double	sy;
	int		stop;
	int		color;
	int		icolor;
}					t_env;

typedef struct		s_var
{
	double	c_r;
	double	c_i;
	int		i;
	double	tmp;
	int		x;
	int		y;
}					t_var;

void				ft_error(int argc, char *str);
void				ft_draw(t_env *e);
int					ft_color_conv(int r, int g, int b);
void				ft_print(int i, int x, int y, t_env *e);
void				ft_display(t_env *e);
void				ft_mandelbrot(t_env *e);
void				ft_julia(t_env *e);
void				ft_mandelbar(t_env *e);
void				mandelbrot(t_env *e);
void				julia(t_env *e);
void				mandelbar(t_env *e);
void				ft_init_mandelbrot(t_env *e);
void				ft_init_julia(t_env *e);
void				ft_init_mandelbar(t_env *e);
int					loop_hook_mandelbrot(t_env *e);
int					loop_hook_julia(t_env *e);
int					loop_hook_mandelbar(t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					mousemove(int x, int y, t_env *e);
int					key_hook(int keycode, t_env *e);
int					expose_hook(t_env *e);
void				key_next(int keycode, t_env *e);
int					mandelbrot_mouse(int button, int x, int y, t_env *e);
int					mandelbar_mouse(int button, int x, int y, t_env *e);
int					julia_mouse(int button, int x, int y, t_env *e);
#endif
