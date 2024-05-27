/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:03:24 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/12 21:43:14 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	count_div_burningship(int x, int y, t_vars *vars)
{
	int		i;
	double	xx;
	double	yy;
	double	tmp;

	i = 0;
	vars->fra.c_x = (double)(x - 200) / \
			(WIDTH * vars->fra.zoom) * 4 + vars->fra.center_x;
	vars->fra.c_y = (double)(y - 200) / \
			(HEIGHT * vars->fra.zoom) * 4 + vars->fra.center_y;
	xx = 0;
	yy = 0;
	while (++i <= 100)
	{
		if (xx * xx + yy * yy > 4)
			return (i);
		tmp = xx;
		xx = xx * xx - yy * yy + vars->fra.c_x;
		tmp = 2 * tmp * yy;
		if (tmp < 0)
			tmp *= -1;
		yy = tmp + vars->fra.c_y;
	}
	return (0);
}

void	draw_burningship(t_vars *vars)
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
			color = count_div_burningship(x, y, vars);
			color = color * vars->fra.colorchange;
			draw_pixel(vars, x, y, color * 10000);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void	burningship(t_vars vars)
{
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Burningship");
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	mlx_hook(vars.win, ON_DESTROY, 0, window_close, &vars);
	mlx_mouse_hook(vars.win, zoom_burningship, &vars);
	mlx_key_hook(vars.win, key_hook_burningship, &vars);
	draw_burningship(&vars);
	mlx_loop(vars.mlx);
}
