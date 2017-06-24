/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:12:53 by tcuer             #+#    #+#             */
/*   Updated: 2016/11/10 12:41:26 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_julia(t_env *e)
{
	t_var v;

	v.x = -1;
	while (++v.x < WIDTH)
	{
		v.y = -1;
		while (++v.y < HEIGHT)
		{
			v.c_r = e->a;
			v.c_i = e->b;
			e->z_r = 0.6 * (v.x - 400) / (0.2 * e->zoom * 800) +
				e->decalx + e->arrow_x;
			e->z_i = 0.8 * (v.y - 400) / (0.28 * e->zoom * 800) +
				e->decaly + e->arrow_y;
			v.i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && v.i < e->i_max)
			{
				v.tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + v.c_r;
				e->z_i = 2 * e->z_i * v.tmp + v.c_i;
				v.i++;
			}
			ft_print(v.i, v.x, v.y, e);
		}
	}
}

int		julia_mouse(int button, int x, int y, t_env *e)
{
	e->x = x;
	e->y = y;
	if (button == 4)
	{
		e->zoom *= 1.1;
		e->decalx += 0.15 * ((((double)x - 400) / (double)400) / e->zoom);
		e->decaly += 0.1425 * ((((double)y - 400) / (double)400) / e->zoom);
		e->i_max++;
	}
	if (button == 5)
	{
		e->zoom /= 1.1;
		e->decalx -= 0.15 * ((((double)x - 400) / (double)400) / e->zoom);
		e->decaly -= 0.1425 * ((((double)y - 400) / (double)400) / e->zoom);
		e->i_max--;
	}
	ft_display(e);
	return (0);
}

void	ft_init_julia(t_env *e)
{
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->r = 0;
	e->g = 0;
	e->b = 0;
	e->i_max = 100;
	e->x = 400;
	e->y = 400;
	e->h = 3;
	e->a = 0;
	e->bl = 0;
	e->zoom = 1;
	e->arrow_x = 0;
	e->arrow_y = 0;
	e->param = 0;
}

int		loop_hook_julia(t_env *e)
{
	ft_julia(e);
	ft_display(e);
	return (0);
}

void	julia(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Julia");
	ft_init_julia(e);
	mlx_hook(e->win, 2, (1L << 0), key_hook, e);
	mlx_hook(e->win, 6, 0, mousemove, e);
	mlx_mouse_hook(e->win, julia_mouse, e);
	mlx_expose_hook(e->win, expose_hook, e);
	ft_display(e);
	mlx_loop_hook(e->mlx, loop_hook_julia, e);
	mlx_loop(e->mlx);
}
