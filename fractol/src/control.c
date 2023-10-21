/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:02:29 by abaccari          #+#    #+#             */
/*   Updated: 2023/10/21 15:34:43 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"
#include "../includes/keycodes_osx.h"

int	key_event(int keycode, t_vars *vars)
{

/*   Change the color of the set */
	
	if (keycode == 69)
		vars->color_shift += 1;
	else if (keycode == 78)
		vars->color_shift -= 1;
	else if (keycode == 53)
		ft_exit(vars);
	return (0);
}

int	mouse_event(int mousecode, int x, int y, t_vars *vars)
{
	/*  Zoom in/out  => doens't work perfectly */

	if (mousecode == 4)
		vars->zoom /= 1.1;
	else if (mousecode == 5)
		vars->zoom *= 1.1;
	if (mousecode == 4 || mousecode == 5)
	{
		vars->mous_x += set_map(x, vars->size.x, -vars->zoom, vars->zoom);
		vars->mous_y += set_map(y, vars->size.y, -vars->zoom, vars->zoom);
	}
	return (0);
}
