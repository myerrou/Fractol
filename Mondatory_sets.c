/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mondatory_sets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <myerrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:03:09 by myerrou           #+#    #+#             */
/*   Updated: 2024/05/16 15:07:38 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

void	mandelbrot_set(t_fcl *fcl)
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
			my_pixel_check(x, y, fcl);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fcl->mlx, fcl->window, fcl->image.img_ptr, 0, 0);
}

void	julia_set(t_fcl *fcl)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			fcl->z.re = (map_shifter(x, -2, 2, WIDTH) * fcl->zoom)
				+ fcl->shift_x;
			fcl->z.i = (map_shifter(y, 2, -2, HEIGHT) * fcl->zoom)
				+ fcl->shift_y;
			fcl->c.re = fcl->cx;
			fcl->c.i = fcl->cy;
			my_pixel_check(x, y, fcl);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fcl->mlx, fcl->window, fcl->image.img_ptr, 0, 0);
}

void	sets_condition(t_fcl *fcl)
{
	if (!ft_strncmp(fcl->name, "julia", 5))
		julia_set(fcl);
	else if (!ft_strncmp(fcl->name, "mandelbrot", 10))
		mandelbrot_set(fcl);
	else
		burning_set(fcl);
}
