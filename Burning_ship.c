/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <myerrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:02:07 by myerrou           #+#    #+#             */
/*   Updated: 2024/05/16 15:07:18 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

void	burning_set(t_fcl *fcl)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			fcl->z.re = 0.0;
			fcl->z.i = 0.0;
			fcl->c.re = (map_shifter(x, -2, 2, WIDTH) * fcl->zoom)
				+ fcl->shift_x;
			fcl->c.i = (map_shifter(y, 2, -2, HEIGHT) * fcl->zoom)
				+ fcl->shift_y;
			pixels_paint(x, y, fcl);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fcl->mlx, fcl->window, fcl->image.img_ptr, 0, 0);
}

void	pixels_paint(int x, int y, t_fcl *fcl)
{
	int	i;
	int	color;

	i = 0;
	while ((fcl->z.re * fcl->z.re + fcl->z.i * fcl->z.i < 4)
		&& i < fcl->iter_def)
	{
		fcl->z = burn_relation(fcl->z, fcl->c);
		i++;
	}
	color = colors(i, BLACK, WHITE, fcl->iter_def);
	if (i == fcl->iter_def)
		my_pixel_put(fcl, x, y, BLACK);
	else
		my_pixel_put(fcl, x, y, color);
}

t_complex	burn_relation(t_complex z, t_complex c)
{
	t_complex	result;

	result.re = z.re * z.re - z.i * z.i + c.re;
	result.i = fabs(2 * z.re * z.i) - c.i;
	return (result);
}
