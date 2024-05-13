#include "Fractol.h"

int	keys_handle(int button, t_fcl *fcl)
{
	if (button == 53)
		close_esc(fcl);
	if (button == 69)
		fcl->iter_def += 1;
	else if (button == 78)
		fcl->iter_def -= 1;
	else if (button == 124)
		fcl->shift_x -= (fcl->zoom / 2);
	else if (button == 123)
		fcl->shift_x += (fcl->zoom / 2);
	else if (button == 125)
		fcl->shift_y += (fcl->zoom / 2);
	else if (button == 126)
		fcl->shift_y -= (fcl->zoom / 2);
	sets_condition(fcl);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_fcl *fcl)
{
	double	old_x;
	double	old_y;
	double	new_x;
	double	new_y;

	old_x = map_shifter(x, -2, 2, WIDTH) * fcl->zoom + fcl->shift_x;
	old_y = map_shifter(y, 2, -2, HEIGHT) * fcl->zoom + fcl->shift_y;
	if (mousecode == 4)
	{
		fcl->zoom /= 2;
		new_x = map_shifter(x, -2, 2, WIDTH) * fcl->zoom + fcl->shift_x;
		new_y = map_shifter(y, 2, -2, HEIGHT) * fcl->zoom + fcl->shift_y;
		fcl->shift_x += old_x - new_x;
		fcl->shift_y += old_y - new_y;
	}
	else if (mousecode == 5)
	{
		fcl->zoom *= 2;
		new_x = map_shifter(x, -2, 2, WIDTH) * fcl->zoom + fcl->shift_x;
		new_y = map_shifter(y, 2, -2, HEIGHT) * fcl->zoom + fcl->shift_y;
		fcl->shift_x += old_x - new_x;
		fcl->shift_y += old_y - new_y;
	}
	sets_condition(fcl);
	return (0);
}

void	hook_func(t_fcl *fcl)
{
	mlx_hook(fcl->window, 4, 0, mouse_hook, fcl);
	mlx_hook(fcl->window, 2, 0, keys_handle, fcl);
	mlx_hook(fcl->window, 6, 0, mouse_move, fcl);
	mlx_hook(fcl->window, 17, 0, close_esc, fcl);
}

int	mouse_move(int x, int y, t_fcl *fcl)
{
	fcl->cx = map_shifter(x, -2, 2, WIDTH) * fcl->zoom;
	fcl->cy = map_shifter(y, 2, -2, HEIGHT) * fcl->zoom;
	sets_condition(fcl);
	return (0);
}

int	close_esc(t_fcl *fcl)
{
	mlx_destroy_image(fcl->mlx, fcl->image.img_ptr);
	mlx_destroy_window(fcl->mlx, fcl->window);
	exit(0);
	return (0);
}
