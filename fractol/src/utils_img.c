/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:07:49 by abaccari          #+#    #+#             */
/*   Updated: 2023/10/10 17:09:13 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"
#include "../includes/keycodes_osx.h"

void	set_pixel(t_vars *dat, int x, int y, int color)
{
	char	*dst;

	dst = dat->addr + (y * dat->line_length + x * (dat->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	set_map(int val, int max, int newmin, int newmax)
{
	double	div;

	div = (double)max / (double)((double)newmax - (double)newmin);
	return ((double)((double)val / (double)div) + (double)newmin);
}

double	set_fract(double val, double max, double newmin, double newmax)
{
	double	d;

	d = (double)max / (double)((double)newmax - (double)newmin);
	return ((double)((double)val / (double)d + (double)newmin));
}

int	set_image(t_vars *dat)
{
	t_vec2d	size;
	int		color;
	int		n;
	int		bright;

	size = (t_vec2d){0, 0};
	mlx_clear_window(dat->mlx, dat->win);
	while (size.x < dat->size.x)
	{
		size.y = 0;
		while (size.y < dat->size.y)
		{
			n = ft_fract_select(dat, size);
			bright = set_map(n, 300, 0, 255);
			if (n == 300)
				bright = 0;
			color = set_color(n, 1000, dat->color_shift) * bright;
			set_pixel(dat, size.x, size.y, color);
			size.y++;
		}
		size.x++;
	}
	mlx_put_image_to_window(dat->mlx, dat->win, dat->img, 0, 0);
	return (0);
}
