/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:44:57 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/10 12:09:51 by pvital-m         ###   ########.fr       */
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
// Set

# define MANDELBROT 1
# define JULIA 2
# define TRICORN 3
// Color
# define ZEBRA 1
# define RAINBOW 2
# define MONO_COLOR 3
// Resulution
# define WIDTH  1280
# define HEIGHT 720
# define TRUNK_SIZE 0.5
# define ANGLE 0.3
// another
# define SHIFT_AMOUNT 10

// # define malloc(x) NULL

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_axis
{
	int		mouse_x;
	int		mouse_y;
	float	offset_x;
	float	offset_y;

}			t_axis;

typedef struct s_win
{
	t_img	*canva;
	t_axis	*mouse;
	int	n;
	int		set;
	void	*mlx_ptr;
	void	*win_ptr;
	float	min_r;
	float	max_r;
	float	min_i;
	float	max_i;
	int		pixel_x;
	int		pixel_y;
	float	cr;
	float	ci;
	float	zoom;
	float	real_x;
	float	fraction_x;
	int		pallete;
	int		color;
}			t_win;

// parsing
void		config_all(char **av, int ac);

// MLX FUNCTIONS
void		place_pixel(t_win *main, int x, int y, int color);
void		update_image_display(t_win *main);
t_win		*screen(void);
t_img		*new_img(int w, int h, t_win *window);
void		create_window(t_win *main, char *name);
void		print_help_screen(void);
int			window_init(void);
int			ft_render_frame(t_win *main);

// Formulas
void		initialize_data(t_win *screen);
void		build(t_win *screen);
float		julia(t_win *screen, double zr, double zi);
float		mandelbrot(float cr, float ci, t_win *screen);
float		tricorn(float const_r, float const_i, t_win *screen);
// Colors Utils;
int			color_percent(int color, double percent);
int			mix_colors(int start, int final, int percent);

// colors
void		create_graph(t_win *screen, float interactions, int x, int y);
void		zebra_pallete(t_win *main, float inte, int x, int y);
void		rainbow_palette(t_win *screen, float interactions, int x, int y);
void	color_shift(int n, int x, int y, float color_shift);

// events
int			key_hook(int keycode, t_win *window);
int			mouse_hook(int button, int x, int y, t_win *window);

// DEBUG ONLY
void		print_data(void);
void		close_program(t_win *screen, char *msg, int status);
#endif