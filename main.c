/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 12:24:09 by tcuer             #+#    #+#             */
/*   Updated: 2016/11/10 10:28:16 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		main(int argc, char **argv)
{
	t_env *e;

	ft_error(argc, argv[1]);
	e = (t_env *)malloc(sizeof(t_env));
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		mandelbrot(e);
	if (ft_strcmp(argv[1], "Julia") == 0)
		julia(e);
	if (ft_strcmp(argv[1], "Mandelbar") == 0)
		mandelbar(e);
	return (0);
}
