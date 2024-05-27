/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:44:58 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/12 19:26:33 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom_julia(int key, int x, int y, t_vars *vars)
{
	x = x + 1 - 1;
	y = y + 1 - 1;
	if (key == ZOOMIN)
		vars->fra.zoom = vars->fra.zoom * 1.25;
	else if (key == ZOOMOUT)
		vars->fra.zoom = vars->fra.zoom * 0.8;
	draw_julia(vars);
	return (0);
}

int	key_hook_julia(int keycode, t_vars *vars)
{
	if (keycode == LEFT)
		vars->fra.center_x -= 0.5 / vars->fra.zoom;
	else if (keycode == RIGHT)
		vars->fra.center_x += 0.5 / vars->fra.zoom;
	else if (keycode == UP)
		vars->fra.center_y -= 0.5 / vars->fra.zoom;
	else if (keycode == DOWN)
		vars->fra.center_y += 0.5 / vars->fra.zoom;
	else if (keycode == ESC)
		window_close(vars);
	else if (keycode == DELETE)
		window_close(vars);
	else if (keycode == SPACE)
		vars->fra.colorchange += 1;
	draw_julia(vars);
	return (0);
}

int	window_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
