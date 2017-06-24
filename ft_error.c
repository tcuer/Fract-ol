/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 12:53:49 by tcuer             #+#    #+#             */
/*   Updated: 2016/11/07 15:26:19 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_error(int argc, char *str)
{
	if (argc > 2)
	{
		ft_putendl("Too many arguments");
		exit(0);
	}
	if (argc == 1)
	{
		ft_putendl("Julia");
		ft_putendl("Mandelbrot");
		ft_putendl("Mandelbar");
		exit(0);
	}
	if (ft_strcmp(str, "Julia") != 0)
	{
		if (ft_strcmp(str, "Mandelbrot") != 0)
		{
			if (ft_strcmp(str, "Mandelbar") != 0)
			{
				ft_putendl("Julia");
				ft_putendl("Mandelbrot");
				ft_putendl("Mandelbar");
				exit(0);
			}
		}
	}
}
