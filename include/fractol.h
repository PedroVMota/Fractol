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

typedef struct s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				width;
	int				height;
	struct s_img	*canva;
}					t_win;

typedef struct s_img
{
	t_win			*win;
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

// Screen Manager
t_win				create_window(int w, int h, char *name);
t_img				new_img(int w, int h, t_win *window);
void				update_image_display(t_win *main);
void				place_pixel(t_win *main, int x, int y, int color);

//events
int					key_hook(int keycode, t_win *window);

//color
int					gen_trgb(int opacity, int red, int green, int blue);
int					get_opacity(int trgb);
int					get_r(int trgb);
int					get_g(int trgb);
int					get_b(int trgb);

//canvas painting
// Parsing Section
int					print_help_screen(void);
bool				ft_check_paramters(char *arg);
#endif