/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:08:16 by abaccari          #+#    #+#             */
/*   Updated: 2023/10/10 17:09:30 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"
#include "../includes/keycodes_osx.h"

int	set_hsv(int n, int shift)
{
	n += shift;
	if (n > 359)
		return (n - 360);
	if (n < 0)
		return (n + 360);
	return (n);
}

int	set_color(int n, int max, int shift)
{
	int	new;
	int	color;

	new = set_hsv(set_map(n, max, 0, 359), shift);
	color = (255 << 16) + (255 << 8) + 255;
	if (n > 240)
		color = ((int)set_map(new - 240, 119, 0, 255)) + ((int)set_map(n - 240,
					119, 255, 0) << 8);
	if (n > 120 && n < 240)
		color = ((int)set_map(new - 120, 119, 255, 0) << 16) + ((int)set_map(n
					- 120, 119, 0, 255) << 8);
	else
		color = ((int)set_map(new, 119, 255, 0)) + ((int)set_map(n, 119, 0,
					255) << 16);
	return (color);
}
