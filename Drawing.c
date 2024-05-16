/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <myerrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:02:20 by myerrou           #+#    #+#             */
/*   Updated: 2024/05/16 15:07:20 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

double	map_shifter(double value, double out_min, double out_max, double in_max)
{
	return ((value * (out_max - out_min) / in_max) + out_min);
}

double	colors(double value, double in_max, double out_min, double out_max)
{
	return ((out_min - in_max) * (value) / out_max + in_max);
}

void	my_pixel_put(t_fcl *fcl, int x, int y, int color)
{
	char	*offset;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		offset = fcl->image.adress + (y * fcl->image.line_len + x
				* (fcl->image.bpp / 8));
		*(unsigned int *)offset = color;
	}
}

t_complex	relation(t_complex z, t_complex c)
{
	t_complex	result;

	result.re = z.re * z.re - z.i * z.i + c.re;
	result.i = 2 * z.re * z.i + c.i;
	return (result);
}

void	my_pixel_check(int x, int y, t_fcl *fcl)
{
	int	i;
	int	color;

	i = 0;
	while ((fcl->z.re * fcl->z.re + fcl->z.i * fcl->z.i < 4)
		&& i < fcl->iter_def)
	{
		fcl->z = relation(fcl->z, fcl->c);
		i++;
	}
	color = colors(i, BLACK, WHITE, fcl->iter_def);
	if (i == fcl->iter_def)
		my_pixel_put(fcl, x, y, GOLD);
	else
		my_pixel_put(fcl, x, y, color);
}
