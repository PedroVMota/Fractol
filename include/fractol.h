#ifndef FRACTOL_MAIN_H
# define FRACTOL_MAIN_H

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

# define ESC 65307
# define UP 65362
# define DOWN 125
# define LEFT 123
# define RIGHT 65363
# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define WIDTH 800
# define HEIGHT 800

typedef struct s_img
{
	//Connection to the window
	struct s_win	*win;
	//Connection to the window
	void			*img_ptr;
	char			*addr;
	int				bit_per_pixel;
	int				w;
	int				h;
	int				endian;
	int				line_len;
	int				x;
	int				y;
}					t_img;

typedef struct s_complex
{
	double			real;
	double			imaginary;

}					t_complex;

typedef struct s_map
{
	double			x_start;
	double			x_end;
	double			y_start;
	double			y_end;
	struct s_win	*win;

}					t_map;

typedef struct s_win
{
	//Connection to the image
	t_img			*canva;
	t_complex		*formula;
	t_map			*ratio;
	//Connection to the image
	void			*mlx_ptr;
	void			*win_ptr;
	int				width;
	int				height;
	int				interactions;
}					t_win;

# define HERE printf("Here\n");
//Struct initialization
t_win				*screen(void);
void				initialize_data(t_win *screen);
void				print_data(t_win *screen);

int					ft_fractal_mandelbrot(t_win *screen, int interaction_max,
						int pixel_x, int pixel_y);
// Screen Manager
void				create_window(t_win *main, char *name);
t_img				*new_img(int w, int h, t_win *window);
void				update_image_display(t_win *main);
void				place_pixel(t_win *main, int x, int y, int color);

//events
int					key_hook(int keycode, t_win *window);

//color
int					gen_trgb(int opacity, int red, int green, int blue);
//canvas painting
// Parsing Section
int					print_help_screen(void);
bool				ft_check_paramters(char *arg);
#endif