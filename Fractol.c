/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <myerrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:02:42 by myerrou           #+#    #+#             */
/*   Updated: 2024/05/16 15:07:25 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

void	mlx_func(t_fcl *fcl)
{
	fcl->iter_def = 150;
	fcl->zoom = 1.0;
	fcl->shift_x = 0.0;
	fcl->shift_y = 0.0;
	fcl->mlx = mlx_init();
	if (!fcl->mlx)
	{
		free(fcl->mlx);
		exit(0);
	}
	fcl->window = mlx_new_window(fcl->mlx, WIDTH, HEIGHT, fcl->name);
	if (!fcl->window)
		mlx_destroy_window(fcl->mlx, fcl->window);
	fcl->image.img_ptr = mlx_new_image(fcl->mlx, WIDTH, HEIGHT);
	fcl->image.adress = mlx_get_data_addr(fcl->image.img_ptr, &fcl->image.bpp,
			&fcl->image.line_len, &fcl->image.endian);
}

int	main(int ac, char **av)
{
	t_fcl	fcl;

	if ((ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 10) || !ft_strncmp(av[1],
					"burningship", 11))) || (ac == 4 && !ft_strncmp(av[1],
				"julia", 5) && s_check(av[2], 0) && s_check(av[3], 0)))
	{
		fcl.name = av[1];
		mlx_func(&fcl);
		if (!ft_strncmp(fcl.name, "mandelbrot", 10))
			mandelbrot_set(&fcl);
		else if (!ft_strncmp(fcl.name, "julia", 5) && ac == 4 && s_check(av[2],
				0) && s_check(av[3], 0))
		{
			fcl.cx = ft_atof(av[2], 0, 0);
			fcl.cy = ft_atof(av[3], 0, 0);
			julia_set(&fcl);
		}
		else if (!ft_strncmp(fcl.name, "burningship", 11))
			burning_set(&fcl);
		hooking_func(&fcl);
		mlx_loop(fcl.mlx);
	}
	else
		(putstr_fd(RC ERR_MESS1, 2), putstr_fd(RC ERR_MESS2, 2));
}
