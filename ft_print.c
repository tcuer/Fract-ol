/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:17:31 by tcuer             #+#    #+#             */
/*   Updated: 2016/11/10 12:38:46 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_print(int i, int x, int y, t_env *e)
{
	e->icolor = i * 255 / e->i_max;
	if (i == e->i_max)
		mlx_pixel_img(e->img, x, y, mlx_get_color_value(e->mlx,
					ft_color_conv(0, 0, 0)));
	else if (i > e->i_max - 15)
	{
		e->bl = 0;
		e->color = ft_color_conv(e->icolor, 255, 0);
		mlx_pixel_img(e->img, x, y, mlx_get_color_value(e->mlx, e->color));
	}
	else if (i > e->i_max - 30)
	{
		e->bl = 0;
		e->color = ft_color_conv(255, e->icolor + e->g, 0);
		mlx_pixel_img(e->img, x, y, mlx_get_color_value(e->mlx, e->color));
	}
	else
	{
		e->bl = e->icolor + 100;
		if (e->bl > 254)
			e->bl = 254;
		e->color = ft_color_conv(e->icolor + e->r, e->icolor + e->g, e->bl);
		mlx_pixel_img(e->img, x, y, mlx_get_color_value(e->mlx, e->color));
	}
}

int		ft_color_conv(int r, int g, int b)
{
	return ((r * 65536) + (g * 256) + b);
}

void	ft_display(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_string_put(e->mlx, e->win, 700, 710, 0xFFFFFF, "x : ");
	mlx_string_put(e->mlx, e->win, 735, 710, 0xFFFFFF, ft_itoa(e->x));
	mlx_string_put(e->mlx, e->win, 700, 730, 0xFFFFFF, "y : ");
	mlx_string_put(e->mlx, e->win, 735, 730, 0xFFFFFF, ft_itoa(e->y));
	mlx_string_put(e->mlx, e->win, 700, 750, 0xFFFFFF, "i : ");
	mlx_string_put(e->mlx, e->win, 735, 750, 0xFFFFFF, ft_itoa(e->i_max));
}
