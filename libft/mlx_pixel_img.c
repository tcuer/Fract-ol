/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 11:42:12 by tcuer             #+#    #+#             */
/*   Updated: 2016/10/07 11:42:34 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	mlx_pixel_img(void *img, int x, int y, int color)
{
	int		i;
	t_img	pxl;

	pxl.info = mlx_get_data_addr(img, &pxl.bits, &pxl.size, &pxl.endian);
	i = x * 4 + y * pxl.size;
	pxl.info[i] = color % 256;
	color /= 256;
	pxl.info[i + 1] = color % 256;
	color /= 256;
	pxl.info[i + 2] = color % 256;
	color /= 256;
	pxl.info[i + 3] = 0;
	color /= 256;
}
