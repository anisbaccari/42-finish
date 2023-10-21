/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:06:51 by abaccari          #+#    #+#             */
/*   Updated: 2023/10/10 17:07:24 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"
#include "../includes/keycodes_osx.h"

int	ft_mandelbrot(t_vars *vars, int x, int y)
{
	t_fract	f;
	int		n;

	f = (t_fract){0, 0, 0, 0, 0, 0, 0};
	f.a = set_fract(x / vars->zoom, vars->size.x / vars->zoom, -vars->zoom
			+ vars->mous_x / 2.5, vars->zoom + vars->mous_x / 2.5);
	f.b = set_fract(y / vars->zoom, vars->size.y / vars->zoom, -vars->zoom
			+ vars->mous_y / 2.5, vars->zoom + vars->mous_y / 2.5);
	n = 0;
	f.ca = f.a;
	f.cb = f.b;
	while (n < 300)
	{
		f.aa = f.a * f.a;
		f.bb = f.b * f.b;
		f.twoab = 2 * f.a * f.b;
		f.a = f.aa - f.bb + f.ca;
		f.b = f.twoab + f.cb;
		if (fabs(f.aa * f.aa + f.bb * f.bb) > 16)
			break ;
		n++;
	}
	return (n);
}

int	ft_julia(t_vars *vars, int x, int y)
{
	t_fract	v;
	int		n;

	v = (t_fract){0, 0, 0, 0, 0, 0, 0};
	v.a = set_fract(x / vars->zoom, vars->size.x / vars->zoom, -vars->zoom
			+ vars->mous_x / 2.5, vars->zoom + vars->mous_x / 2.5);
	v.b = set_fract(y / vars->zoom, vars->size.y / vars->zoom, -vars->zoom
			+ vars->mous_y / 2.5, vars->zoom + vars->mous_y / 2.5);
	n = 0;
	while (n < 300)
	{
		v.aa = v.a * v.a;
		v.bb = v.b * v.b;
		v.twoab = 2 * v.a * v.b;
		v.a = v.aa - v.bb + vars->julia_x;
		v.b = v.twoab + vars->julia_y;
		if (fabs(v.aa * v.aa + v.bb * v.bb) > 16)
			break ;
		n++ ;
	}
	return (n);
}

int	ft_fract_select(t_vars *vars, t_vec2d v)
{
	if (vars->fractmode == 1)
		return (ft_mandelbrot(vars, v.x, v.y));
	else if (vars->fractmode == 2)
		return (ft_julia(vars, v.x, v.y));
	return (0);
}
