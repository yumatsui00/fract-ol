/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:42:48 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/12 21:37:22 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <mlx.h>

# define WIDTH 400
# define HEIGHT 400

typedef struct s_frac
{
	double	c_y;
	double	c_x;
	double	z_y;
	double	z_x;
	double	center_x;
	double	center_y;
	double	zoom;
	int		colorchange;
}	t_frac;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_frac	fra;
	char	*arg;
}	t_vars;

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define MOUSEDOWN 4
//mlx_mouse_hook(rool_up = zoom in, roll down = zoom out)
# define ZOOMOUT 4
# define ZOOMIN 5
//mlx_key_hook
# define ON_DESTROY 17
# define ESC 53
# define DELETE 51
# define SPACE 49
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

void	initializer(t_vars *vars);
int		window_close(t_vars *vars);
double	ft_atod(char *str);
void	draw_pixel(t_vars *vars, int x, int y, unsigned int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);
void	end(char *cause);
void	julia(t_vars vars);
void	draw_julia(t_vars *vars);
int		zoom_julia(int key, int x, int y, t_vars *vars);
int		key_hook_julia(int keycode, t_vars *vars);
void	mandelbrot(t_vars vars);
void	draw_mandelbrot(t_vars *vars);
int		zoom_mandel(int key, int x, int y, t_vars *vars);
int		key_hook_mandel(int keycode, t_vars *vars);
void	burningship(t_vars vars);
void	draw_burningship(t_vars *vars);
int		zoom_burningship(int key, int x, int y, t_vars *vars);
int		key_hook_burningship(int keycode, t_vars *vars);

#endif