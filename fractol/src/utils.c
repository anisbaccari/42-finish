/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:10:45 by abaccari          #+#    #+#             */
/*   Updated: 2023/10/10 17:16:13 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"
#include "../includes/keycodes_osx.h"

int	ft_strcmp(const char *a, const char *b)
{
	while ((a && b) && (*a || *b))
	{
		if ((unsigned char)*a != (unsigned char)*b)
			return ((unsigned char)*a - (unsigned char)*b);
		a++;
		b++;
	}
	return (0);
}

double	ft_atod(char *s)
{
	double	n;
	double	neg;
	double	div;

	n = 0;
	neg = 1;
	div = 0.1;
	if (!s)
		return (n);
	while (*s && ((*s >= 9 && *s <= 13) || *s == 32))
		s++;
	if (*s && (*s == '-' || *s == '+'))
		if (*s++ == '-')
			neg = -1;
	while (*s && ft_isdigit(*s))
		n = n * 10 + *s++ - 48;
	if (*s && *s == '.')
		s++;
	while (*s && ft_isdigit(*s))
	{
		n += (*s++ - 48) * div;
		div /= 10;
	}
	return (n * neg);
}

int	ft_exit(t_vars *v)
{
	mlx_destroy_image(v->mlx, v->img);
	mlx_destroy_window(v->mlx, v->win);
	exit(0);
}

void	ft_error(void)
{
	ft_printf("\n\tinvalide arguments \n");
	ft_printf("Enter either :\n- mandelbrot\n\t\tor\n- julia (double)x (double)y\n");
	exit(0);
}
