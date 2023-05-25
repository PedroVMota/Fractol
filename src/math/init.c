#include "fractol.h"

double	map(float x, float input_min, float input_max, float output_min,
		float output_max)
{
	return (((x - input_min) / (input_max - input_min)) * (output_max
			- output_min) + output_min);
}

int	ft_fractal_mandelbrot(t_win *screen, int interaction_max, int pixel_x,
		int pixel_y)

{
	int interactions;

	interactions = 0;

	/*
		zoom effect
	*/
	screen->mandelbrot->ratio_x = map(pixel_x, 0, screen->width, -2 * screen->offset_x, 2 * screen->zoom);
	screen->mandelbrot->ratio_y = map(pixel_y, 0, screen->height, -2 * screen->offset_y, 2 * screen->zoom);
	/* screen->mandelbrot->ratio_x = map(pixel_x, 0, screen->width, -2, 2);
	screen->mandelbrot->ratio_y = map(pixel_y, 0, screen->height, -2, 2); */
	screen->mandelbrot->constant_a = screen->mandelbrot->ratio_x;
	screen->mandelbrot->constant_b = screen->mandelbrot->ratio_y;
	while (interactions < interaction_max)
	{
		screen->mandelbrot->real_part = pow(screen->mandelbrot->ratio_x, 2)
			- pow(screen->mandelbrot->ratio_y, 2);
		screen->mandelbrot->imaginary_part = 2 * screen->mandelbrot->ratio_x
			* screen->mandelbrot->ratio_y;

		screen->mandelbrot->ratio_x = screen->mandelbrot->real_part
			+ screen->mandelbrot->constant_a;
		screen->mandelbrot->ratio_y = screen->mandelbrot->imaginary_part
			+ screen->mandelbrot->constant_b;
		if (fabs(screen->mandelbrot->ratio_x
				+ screen->mandelbrot->ratio_y) > 3.0)
			break ;
		interactions++;
	}
	return (interactions);
}

int	ft_fractal_julia(t_win *screen, int interaction_max, int pixel_x,
		int pixel_y)
{
	int interactions;

	interactions = 0;
	screen->julia->ratio_x = map(pixel_x + screen->mouse_x, 0, screen->width, -2 * screen->offset_x, 2 + screen->zoom);
	screen->julia->ratio_y = map(pixel_y + screen->mouse_y, 0, screen->height, -2 * screen->offset_y, 2 + screen->zoom);
	while (interactions < interaction_max)
	{
		screen->julia->real_part = pow(screen->julia->ratio_x, 2)
			- pow(screen->julia->ratio_y, 2);
		screen->julia->imaginary_part = 2 * screen->julia->ratio_x
			* screen->julia->ratio_y;

		screen->julia->ratio_x = screen->julia->real_part
			+ screen->julia->constant_a;
		screen->julia->ratio_y = screen->julia->imaginary_part
			+ screen->julia->constant_b;
		if (fabs(screen->julia->ratio_x + screen->julia->ratio_y) > 14.0)
			break ;

		interactions++;
	}

	return (interactions);
}