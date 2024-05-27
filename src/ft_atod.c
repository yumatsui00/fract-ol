/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:57:31 by yumatsui          #+#    #+#             */
/*   Updated: 2024/05/11 16:44:18 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

static void	checker(char c, double *dotflag)
{
	if ((c > '9' || c < '0') && c != '.')
		ft_error();
	if (c == '.')
	{
		*dotflag += 1;
		if (*dotflag >= 2)
			ft_error();
	}
}

static void	ft_atod2(double *ans, long *count, int *countflag, char c)
{
	if (c == '.')
		*countflag = 1;
	else
	{
		*ans = *ans * 10 + (c - '0');
		if (*countflag == 1)
			*count *= 10;
		if (*count >= 1000000000000000000)
			ft_error();
	}
}

double	ft_atod(char *str)
{
	double	ans;
	double	flag;
	double	dotflag;
	int		countflag;
	long	count;

	ans = 0;
	dotflag = 0;
	flag = 1;
	countflag = 0;
	count = 1;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	while (*str)
	{
		checker(*str, &dotflag);
		ft_atod2(&ans, &count, &countflag, *str);
		str++;
		if (ans / count > INT_MAX || ans * flag / count < INT_MIN)
			ft_error();
	}
	return (flag * ans / count);
}

// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	double	i;
// 	argc = 0;
// 	i = ft_atod(argv[1]);
// 	printf("ans = %lf\n", i);
// 	return (0);
// }