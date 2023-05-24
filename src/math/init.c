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
	double ratio_x;
	double ratio_y;
	double real_part;
	double imaginary_part;

	interactions = 0;
	ratio_x = map(pixel_x, 0, screen->width, -2, 2);
	ratio_y = map(pixel_y, 0, screen->height, -2, 2);
	while (interactions < interaction_max)
	{
		real_part = pow(ratio_x, 2) - pow(ratio_y, 2);
		imaginary_part = 2 * ratio_x * ratio_y;

		ratio_x = real_part;
		ratio_y = imaginary_part;
		if (fabs(ratio_x + ratio_y) > 4.0)
			break ;
		interactions++;
	}
	return (interactions);
}
