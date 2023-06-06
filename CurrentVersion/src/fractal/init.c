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
void	build(t_win *screen)
{
	int x;
	int y;
	double cr;
	double ci;
	int interactions;

	interactions = 0;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			cr = screen->min_real + ((double)x / WIDTH) * (screen->max_real
					- screen->min_real);
			ci = screen->min_imaginary + ((double)y / HEIGHT)
				* (screen->max_imaginary - screen->min_imaginary);
			interactions = fractal_selector(screen, cr, ci);
			create_graph(screen, interactions, x, y);
		}
	}
	update_image_display(screen);
}