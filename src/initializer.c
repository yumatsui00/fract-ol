/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 12:06:28 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/12 19:18:45 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initializer(t_vars *vars)
{
	vars->fra.center_x = 0;
	vars->fra.center_y = 0;
	vars->fra.zoom = 1;
	vars->fra.colorchange = 1;
}
