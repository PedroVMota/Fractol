/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:44:57 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/06 00:32:52 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "ft_colors.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <math.h>
#include <mlx.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef FRACTAL_TYPES_H
	#define FRACTAL_TYPES_H
		#define MANDELBROT 1
		#define JULIA 2
#endif

#ifndef COLOR_PALETTES_H
	#define COLOR_PALETTES_H
		#define ZEBRA 1
		#define RAINBOW 2
#endif

#define ESC 53
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define SCROLL_UP 4
#define SCROLL_DOWN 5

#define WIDTH 500
#define HEIGHT 500

#define MAX_INTERACTIONS 150

typedef struct s_img
{
	void *img_ptr;
	char *addr;
	int bpp;
	int endian;
	int line_len;
} t_img;

typedef struct s_win
{
	t_img *canva;
	int set;
	void *mlx_ptr;
	void *win_ptr;
	int min_real;
	int max_real;
	int min_imaginary;
	int max_imaginary;
	float constant_real;
	float constant_imaginary;
	float scale;
	float real_x;
	float fraction_x;
	int pallete;
} t_win;

//parsing
void config_all(char **av);

//MLX FUNCTIONS 
void	place_pixel(t_win *main, int x, int y, int color);
void	update_image_display(t_win *main);
t_win *screen(void);
t_img *new_img(int w, int h, t_win *window);
void	create_window(t_win *main, char *name);
void	print_help_screen(void);
int	window_init();
int	ft_render_frame(t_win *main);


// Formulas
void initialize_data(t_win *screen);
void build(t_win *screen);
int julia(t_win *screen, double zr, double zi);
int	mandelbrot(int cr, int ci);

//colors
void create_graph(t_win *screen, int interactions, int x, int y);
void	zebra_pallete(t_win *main, int inte, int x, int y);

//events
int	key_hook(int keycode, t_win *window);
int	mouse_hook(int button, int x, int y, t_win *window);

// DEBUG ONLY
void print_data(t_win *screen);
void close_program(t_win *screen);
#endif