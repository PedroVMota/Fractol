#include "fractol.h"

static int	fractal_selector(t_win *screen, double real_part,
		double imaginary_part)
{
	if (screen->set == JULIA)
		return (julia(screen, real_part, imaginary_part));
	else if (screen->set == MANDELBROT)
		return (mandelbrot(real_part, imaginary_part, screen));
	return (0);
}

/*
typedef struct s_win
{
	t_img	*canva;
	int		set;
	void	*mlx_ptr;
	void	*win_ptr;
	int		min_real;
	int		max_real;
	int		min_imaginary;
	int		max_imaginary;
	int		pixel_x;
	int		pixel_y;
	float	cr;
	float	ci;
	float	zoom;
	float	real_x;
	float	fraction_x;
	int		pallete;
}			t_win;

*/
double	set_value(double min_value, double max_value, int coord, int total)
{
	double	range;
	double	position;
	double	value;
	double	zoomed_value;

	range = max_value - min_value;
	position = (double)coord / total;
	value = min_value + position * range;
	zoomed_value = value / screen()->zoom;
	return (zoomed_value);
}

void	build(t_win *screen)
{
	int		x;
	int		y;
	double	cr;
	double	ci;
	int		interactions;

	interactions = 0;
	y = -1;
	ci = 0;
	cr = 0;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			cr = set_value(screen->min_r, screen->max_r, x + screen->mouse->mouse_x, WIDTH - 1);
            ci = set_value(screen->min_i, screen->max_i, y + screen->mouse->mouse_y, HEIGHT - 1);
			interactions = fractal_selector(screen, cr, ci);
			create_graph(screen, interactions, x, y);
		}
	}
	update_image_display(screen);
}
