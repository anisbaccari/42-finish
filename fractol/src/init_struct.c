/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:54:17 by abaccari          #+#    #+#             */
/*   Updated: 2023/10/10 18:44:06 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"
#include "../includes/keycodes_osx.h"

void	init_struct(t_vars *vars)
{
	*vars = (t_vars){NULL, NULL, NULL, NULL, 0, 0, 0, (t_vec2d){500, 500}, 2.5,
		0, 0, 0, 0, 0, 0};
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->size.x, vars->size.y,
			"Hello world!");
	vars->img = mlx_new_image(vars->mlx, vars->size.x, vars->size.y);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	return ;
}
