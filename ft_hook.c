/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:27:26 by tcuer             #+#    #+#             */
/*   Updated: 2016/11/10 12:45:18 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		expose_hook(t_env *e)
{
	mlx_do_sync(e->mlx);
	ft_display(e);
	return (0);
}

void	key_next(int keycode, t_env *e)
{
	if (keycode == 49)
	{
		if (e->stop == 0)
			e->stop = 1;
		else if (e->stop == 1)
			e->stop = 0;
	}
	if (keycode == 123)
		e->arrow_x -= 0.20 / e->zoom;
	if (keycode == 124)
		e->arrow_x += 0.20 / e->zoom;
	if (keycode == 125)
		e->arrow_y += 0.20 / e->zoom;
	if (keycode == 126)
		e->arrow_y -= 0.20 / e->zoom;
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 83)
		e->r += -5;
	if (keycode == 84)
		e->g += -5;
	if (keycode == 85)
		e->bl += -5;
	if (keycode == 86)
		e->r += 5;
	if (keycode == 87)
		e->g += 5;
	if (keycode == 88)
		e->bl += 5;
	if (keycode == 69)
		e->i_max += 5;
	if (keycode == 78)
		e->i_max -= 5;
	key_next(keycode, e);
	return (0);
}

int		mousemove(int x, int y, t_env *e)
{
	if (e->stop != 1 && x < WIDTH && y < HEIGHT && x > 0 && y > 0)
	{
		e->a = ((((long double)x - 400) / (long double)400) / e->zoom);
		e->b = ((((long double)y - 400) / (long double)400) / e->zoom);
	}
	return (1);
}
