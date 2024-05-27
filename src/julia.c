/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:18:59 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/12 21:37:39 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	count_div_julia(int x, int y, t_vars *vars)
{
	int		i;
	double	xx;
	double	yy;
	double	tmp;

	i = 0;
	xx = (double)(x - 200) / (WIDTH * vars->fra.zoom) * 4 + vars->fra.center_x;
	yy = (double)(y - 200) / (HEIGHT * vars->fra.zoom) * 4 + vars->fra.center_y;
	while (++i <= 100)
	{
		if (xx * xx + yy * yy > 4)
			return (i);
		tmp = xx;
		xx = xx * xx - yy * yy + vars->fra.c_x;
		yy = 2 * tmp * yy + vars->fra.c_y;
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_pixel(t_vars *vars, int x, int y, unsigned int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	my_mlx_pixel_put(&vars->img, x, y, color);
}

void	draw_julia(t_vars *vars)
{
	int	x;
	int	y;
	int	color;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			color = count_div_julia(x, y, vars);
			color = color * vars->fra.colorchange;
			draw_pixel(vars, x, y, color * 10000);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void	julia(t_vars vars)
{
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Julia");
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	mlx_hook(vars.win, ON_DESTROY, 0, window_close, &vars);
	mlx_mouse_hook(vars.win, zoom_julia, &vars);
	mlx_key_hook(vars.win, key_hook_julia, &vars);
	draw_julia(&vars);
	mlx_loop(vars.mlx);
}
