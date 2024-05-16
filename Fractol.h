/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <myerrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:03:00 by myerrou           #+#    #+#             */
/*   Updated: 2024/05/16 15:07:28 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define ERR_MESS1 "Error! Please enter [./Fractol] followed by : \n  [mandel"
# define ERR_MESS2 "brot]\nor\n  [julia] [arg1] [arg2]\nor\n  [burningship] \n"
# define RC "\033[0;31m"
# define NC "\033[0;0m"
# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000      // Black color
# define WHITE 0xFFFFFF      // White color
# define RED 0xFF0000        // Red color
# define GREEN 0x00FF00      // Green color
# define BLUE 0x0000FF       // Blue color
# define MAGENTA 0xFF00FF    // Magenta color
# define ORANGE 0xFFA500     // Orange color
# define PURPLE 0x800080     // Purple color
# define DARK_GREEN 0x006400 // Dark Green color
# define GOLD 0xFFD700       // Gold color

typedef struct s_complex
{
	double		re;
	double		i;
}				t_complex;

typedef struct s_image
{
	void		*img_ptr;
	char		*adress;
	int			line_len;
	int			endian;
	int			bpp;
}				t_image;

typedef struct s_fcl
{
	void		*mlx;
	void		*window;
	char		*name;
	int			iter_def;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		x;
	double		y;
	double		cx;
	double		cy;
	t_image		image;
	t_complex	z;
	t_complex	c;
}				t_fcl;

int				mouse_hook(int mousecode, int x, int y, t_fcl *fcl);
int				ft_strncmp(char *s1, char *s2, size_t n);
int				motion_mouse(int x, int y, t_fcl *fcl);
int				keys_handle(int keycode, t_fcl *fcl);
int				s_check(const char *str, int i);
int				close_esc(t_fcl *fcl);
double			map_shifter(double value, double out_min, double out_max,
					double in_max);
double			colors(double value, double in_max, double out_min,
					double out_max);
double			ft_atof(const char *str, long in, double frac);
void			putstr_fd(char *s, int fd);
void			my_pixel_put(t_fcl *fcl, int x, int y, int color);
void			my_pixel_check(int x, int y, t_fcl *fcl);
void			pixels_paint(int x, int y, t_fcl *fcl);
void			mandelbrot_set(t_fcl *fcl);
void			sets_condition(t_fcl *fcl);
void			burning_set(t_fcl *fcl);
void			hooking_func(t_fcl *fcl);
void			julia_set(t_fcl *fcl);
void			mlx_func(t_fcl *fcl);
t_complex		burn_relation(t_complex z, t_complex c);
t_complex		relation(t_complex z, t_complex c);

#endif
