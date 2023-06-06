#include "fractol.h"

static int fractal_selector(t_win *screen, double real_part, double imaginary_part)
{
	if(screen->set == JULIA)
		return (julia(screen, real_part, imaginary_part));
	else if(screen->set == MANDELBROT)
		return (mandelbrot(real_part, imaginary_part));
	return 0;
}

void build(t_win *screen)
{
	int x;
	int y;
	double real_part;
	double imaginary_part;
	int interactions;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			real_part = screen->min_real + x * (screen->max_real - screen->min_real) / WIDTH;
			imaginary_part = screen->min_imaginary + y * (screen->max_imaginary - screen->min_imaginary) / HEIGHT;
			interactions = fractal_selector(screen, real_part, imaginary_part);
			create_graph(screen, interactions, x, y);
		}
	}
	update_image_display(screen);
}