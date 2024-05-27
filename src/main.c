/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:45:42 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/12 21:23:03 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	end(char *cause)
{
	int	count;

	count = 0;
	while (cause[count])
		count++;
	write(2, cause, count);
	write(1, "\n", 1);
	exit(1);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n > 0 && *s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		n--;
		s1++;
		s2++;
	}
	if (n > 0)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	return (0);
}

void	check_args(t_vars *vars, int argc, char **argv)
{
	if (argc != 4)
		end("Invalid args : select 2 doubel-type numbers when julia");
	vars->fra.c_x = ft_atod(argv[2]);
	vars->fra.c_y = ft_atod(argv[3]);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc <= 1)
		end("select one fractols : julia, mandel, ship");
	initializer(&vars);
	if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		check_args(&vars, argc, argv);
		julia(vars);
	}
	else if (ft_strncmp(argv[1], "mandel", 7) == 0 && argc == 2)
		mandelbrot(vars);
	else if (ft_strncmp(argv[1], "ship", 5) == 0 && argc == 2)
		burningship(vars);
	else
		end("Available fractals : julia, mandel, ship");
}
