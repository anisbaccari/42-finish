/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:09:47 by abaccari          #+#    #+#             */
/*   Updated: 2023/10/11 13:32:54 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fract_ol.h"
#include "includes/keycodes_osx.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	(void)argv;
	init_struct(&vars);
	if (argc < 2)
		ft_error();
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 12))
		vars.fractmode = 1;
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 7))
	{
		vars.fractmode = 2;
		vars.julia_x = ft_atod(argv[2]);
		vars.julia_y = ft_atod(argv[3]);
	}
	else
		ft_error();
	mlx_key_hook(vars.win, key_event, (void *)&vars);
	mlx_mouse_hook(vars.win, mouse_event, (void *)&vars);
	mlx_loop_hook(vars.mlx, set_image, (void *)&vars);
	mlx_hook(vars.win, 17, 0, ft_exit, (void *)&vars);
	mlx_do_key_autorepeaton(vars.mlx);
	mlx_loop(vars.mlx);
	ft_exit(&vars);
	system("leaks fractol");
	return (0);
}
