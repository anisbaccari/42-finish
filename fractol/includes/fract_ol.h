/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:03:47 by abaccari          #+#    #+#             */
/*   Updated: 2023/10/11 13:15:06 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "ft_printf/includes/ft_printf.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 512
# define HEIGHT 512

typedef struct s_vec2d
{
	int		x;
	int		y;
}			t_vec2d;

typedef struct s_fract
{
	double	a;
	double	b;
	double	aa;
	double	bb;
	double	twoab;
	double	ca;
	double	cb;
}			t_fract;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_vec2d	size;
	double	zoom;
	double	mous_x;
	double	mous_y;
	int		color_shift;
	int		fractmode;
	double	julia_x;
	double	julia_y;
}			t_vars;
/* ------- STRUCTURE / INIT----- */
void		init_struct(t_vars *vars);

/* ------- UTILS----- */
int			ft_strcmp(const char *a, const char *b);
double		ft_atod(char *s);
int			ft_exit(t_vars *v);
void		ft_error(void);

/* ------- UTILS-IMG----- */
int			set_image(t_vars *dat);
double		set_map(int val, int max, int newmin, int newmax);
void		set_pixel(t_vars *dat, int x, int y, int color);
int			set_color(int n, int max, int shift);
int			set_hsv(int n, int shift);
double		set_fract(double val, double max, double newmin, double newmax);

/* ------- UTILS-CONTROL----- */
int			mouse_event(int keycode, int x, int y, t_vars *vars);
int			key_event(int keycode, t_vars *vars);
/* ------- UTILS-FRACTAL----- */

int			ft_mandelbrot(t_vars *vars, int x, int y);
int			ft_fract_select(t_vars *vars, t_vec2d v);
int			ft_julia(t_vars *vars, int x, int y);
#endif