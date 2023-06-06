/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:44:57 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/05 12:48:55 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_colors.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>


#define PROBLEM printf("Problem\n");
# define WIDTH 800
# define HEIGHT 800
# define MAX_INTERACTIONS 1000

//Define types
#define MANDELBROT 1
#define JULIA 2

/*
	What is each element:
	mlx: mlx pointer
	win: window pointer
	img: image pointer
	addr: image address
	bpp: bits per pixel
	line_len: line length
	endian: endian
	type: type of fractal
	min_r: min real
	max_r: max real
	min_i: min imaginary
	max_i: max imaginary
	kr: real constant
	ki: imaginary constant
	sx: scale x
	rx: real x
	fx: fraction x
	color_pattern: color pattern
*/

typedef struct s_fractal
{
	void *mlx;
	void *win;
	void *img;
	char *addr;
	int bpp;
	int line_len;
	int endian;
	int type;
	double min_r;
	double max_r;
	double min_i;
	double max_i;
	double kr;
	double ki;
	double sx;
	double rx;
	double fx;
	int *palete;
	int color_pattern;
	int color;

} t_fractal;

void	render(t_fractal *f);

void set_args(char **av, int ac, t_fractal *all);
void print_help_screen(void);

void close_and_clean(int exit_status, char *msg, t_fractal *all);
void	new_img(t_fractal *all);
void	reset_img(t_fractal *all);
void	start_data_preset(t_fractal *all);
void set_data_fractal(t_fractal *all);

void set_colors(t_fractal *all, char **av, int ac);
void color_mode(t_fractal *all);
void set_pattern(t_fractal *all);
void black_and_white(t_fractal *all, int color);
void rainbow_set_color(t_fractal *all, int colors[4], int n);
void set_monocromatic_color(t_fractal *all, int color);
int	convert_color_to_percent(int color, double percent);
int	color_blender(int color_beggin, int final_color, double fraction);
void	fill_color(t_fractal *all, int color, int stripe);


int	mandelbrot(double cr, double ci);
int	julia(t_fractal *all, double zr, double zi);

#endif