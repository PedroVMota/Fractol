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

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_img
{
	struct s_win	*win;
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

typedef struct s_mandelbrot
{
	double			ratio_x;
	double			ratio_y;
	double			real_part;
	double			imaginary_part;
	double			constant_a;
	double			constant_b;
}					t_mandelbrot;

typedef struct s_julia
{
	double			ratio_x;
	double			ratio_y;
	double			real_part;
	double			imaginary_part;
	double			constant_a;
	double			constant_b;
}					t_julia;

typedef struct s_win
{
	t_img			*canva;
	t_julia			*julia;
	t_mandelbrot	*mandelbrot;
	void			*mlx_ptr;
	void			*win_ptr;
	int				width;
	int				height;
	int				mouse_x;
	int				mouse_y;
	int				image_x;
	int				image_y;
	int option;
}					t_win;

# define HERE printf("Here\n");
t_win				*screen(void);
t_img				*new_img(int w, int h, t_win *window);
int					ft_fractal_mandelbrot(t_win *screen, int interaction_max,
						int pixel_x, int pixel_y);
int					ft_fractal_julia(t_win *screen, int interaction_max,
						int pixel_x, int pixel_y);

void				color_palette(t_win *main, int inte, int x, int y);
void				screen_update_canvas(t_win *screen, int max);
void				create_window(t_win *main, char *name);
void				update_image_display(t_win *main);
void				place_pixel(t_win *main, int x, int y, int color);
int					key_hook(int keycode, t_win *window);
int					key_hook_mouse(int keycode, t_win *window);
int					gen_trgb(int opacity, int red, int green, int blue);
void				color_palette(t_win *main, int inte, int x, int y);
int					print_help_screen(void);
bool				ft_check_paramters(char *arg);
double				map(float x, float input_min, float input_max,
						float output_min, float output_max);

//Formulas
int					initialize_data(t_win *screen, int fractal);
void				mandelbro_calculation(t_win *screen, int max);
void				julia_calculation(t_win *screen, int max);

//DEBUG ONLY
void				print_data(t_win *screen);
#endif